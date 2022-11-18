#include "CommandReader.h"
#include <iostream>
#include "TestCase.h"
#include "Robot.h"
#include <algorithm>
#include <sstream>

void CommandReader::readCommand() {
    std::ifstream ifs(test_file);
    std::cout << "Reading from " << test_file << std::endl;
    if (!ifs) {
        std::cerr << "Could not read the test file\n";
        exit(1);
    } else {
        Robot startState;
        Robot endState;
        std::string line{};
        std::vector<std::string> tmpCommands;
        while (std::getline(ifs, line)) {
            if(line.empty())
                break;
            if (line.find("PLACE") != std::string::npos) {
                tmpCommands.clear();
                std::istringstream iss(line);
                startState = extractRobotStateFromPlaceString(line);
                //std::cout << "Start position is " << startState << std::endl;
            } else if (isCommand(line)) {
                tmpCommands.push_back(line);
            } else if (line.find("Output") != std::string::npos) {
                endState = extractRobotStateFromOutputString(line);
                //std::cout << "End position is " << endState << std::endl;
                TestCase testCase;
                testCase.setStartStart(startState);
                testCase.setActions(tmpCommands);
                testCase.setEndState(endState);
                testCases.push_back(testCase);
            }
        }
    }

}

Robot CommandReader::extractRobotStateFromPlaceString(const std::string &line) {
    // PLACE 1,2,EAST
    char c{','};
    const auto info = line.substr(line.find(' ') + 1);
    int x{}, y{};
    std::string direction{};
    std::istringstream iss(info);
    iss >> x >> c >> y >> direction;
    const Robot robot({x, y}, stringToDirection(direction));
    return robot;
}

bool CommandReader::isCommand(const std::string &line) {
    return line == "MOVE" || line == "LEFT" || line == "RIGHT" || line == "REPORT";
}

Robot CommandReader::extractRobotStateFromOutputString(const std::string &line) {
    const auto info = line.substr(line.find(':') + 2);
    int x{}, y{};
    std::string direction{};
    char c{','};
    std::istringstream iss(info);
    iss >> x >> c >> y >> direction;
    const Robot robot({x, y}, stringToDirection(direction));
    return robot;
}

std::vector<TestCase> CommandReader::getTestCases() const {
    return testCases;
}


