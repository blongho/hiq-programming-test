
#include "TestCaseReader.h"
#include "Robot.h"


int main() {
    TestCaseReader commandReader;
    commandReader.readCommand();
    const auto testCases = commandReader.getTestCases();
    for (const auto &item: testCases) {
        for (const auto &action: item.getActions()) {
            std::cout << action << ",";
        }
    }
    Robot robot({0, 4}, Direction::NORTH);
    robot.move();
    robot.right();
    robot.move();
    robot.move();
    robot.report();
    std::cin.get();
    return 0;
}


