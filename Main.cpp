#include "TestCaseReader.h"
#include "Robot.h"
#include <numeric>

int main() {
    TestCaseReader commandReader("../test_cases.txt");
    commandReader.readCommand();
    const auto testCases = commandReader.getTestCases();
    std::cout << "Number of test cases " << testCases.size() << std::endl;
    auto  testActionCount{0u};
    for (const auto &item: testCases){
        testActionCount += item.getActions().size();
    }
    std::cout << "Sum of actions " << testActionCount << std::endl;

    for (const auto &testCase: testCases) {
        Robot robot = testCase.getStartState();
        for (const auto &action: testCase.getActions()) {
            robot.performAction(action);
            std::cout << action << std::endl;
        }
    }

    return 0;
}


