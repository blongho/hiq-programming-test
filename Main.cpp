
#include "TestCaseReader.h"
#include "Robot.h"


int main() {
    TestCaseReader commandReader("../test_cases.txt");
    commandReader.readCommand();
    const auto testCases = commandReader.getTestCases();
    for (const auto &testCase: testCases) {
        Robot robot = testCase.getStartState();
        for (const auto &action: testCase.getActions()) {
            robot.performAction(action);
        }
    }

    return 0;
}


