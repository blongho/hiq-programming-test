#include "TestCaseReader.h"
#include <iostream>
#include "TestCase.h"
#include "Robot.h"
#include <algorithm>
#include <sstream>
#include <utility>

void TestCaseReader::readCommand() {
    std::ifstream ifs(test_file);
    std::cout << __func__ << ": Reading from " << test_file << "\n\n";
    if (!ifs) {
        throw std::runtime_error(std::string(__func__)  +": test file could not be read!");
    } else {
        Robot startState;
        Robot endState;
        std::string line{};
        std::vector<Action> tmpCommands;
        while (std::getline(ifs, line)) {
            if (!line.empty() || line[0] == '#') {
                if (line.find("PLACE") != std::string::npos) {
                    tmpCommands.clear();
                    std::istringstream iss(line);
                    startState = extractRobotStateFromPlaceString(line);
                    //std::cout << "Start position is " << startState << std::endl;
                } else if (isAction(line)) {
                    tmpCommands.push_back(actionFromString(line));
                } else if (line.find("Output") != std::string::npos) {
                    endState = extractRobotStateFromOutputString(line);
                    //std::cout << "End position is " << endState << std::endl;
                    TestCase testCase;
                    testCase.setStartState(startState);
                    testCase.setActions(tmpCommands);
                    testCase.setEndState(endState);
                    testCases.push_back(testCase);
                }
            } else {
                /* std::cout << __FILE_NAME__ << ":" << __func__ << ":" << __LINE__
                           << ": Empty line or comment in the tests file. Ignored!!\n";*/
                continue;
            }
        }
        std::cout << "Test content successfully read\n";
    }

}

Robot TestCaseReader::extractRobotStateFromPlaceString(const std::string &line) {
    // PLACE 1,2,EAST
    char c{','};
    const auto info = line.substr(line.find(' ') + 1);
    short x{}, y{};
    std::string direction{};
    std::istringstream iss(info);
    iss >> x >> c >> y >> c >> direction;
    const Robot robot({x, y}, stringToDirection(direction));
    return robot;
}

bool TestCaseReader::isAction(const std::string &basicString) {
    return basicString == "MOVE" || basicString == "LEFT" || basicString == "RIGHT" || basicString == "REPORT";
}

Robot TestCaseReader::extractRobotStateFromOutputString(const std::string &line) {
    const auto info = line.substr(line.find(':') + 2);
    short x{}, y{};
    std::string direction{};
    char c{','};
    std::istringstream iss(info);
    iss >> x >> c >> y >> c >> direction;

    const Robot robot({x, y}, stringToDirection(direction));
    return robot;
}

std::vector<TestCase> TestCaseReader::getTestCases() const {
    return testCases;
}

TestCaseReader::TestCaseReader(std::string testCaseFile)
        : test_file{std::move(testCaseFile)} {}



