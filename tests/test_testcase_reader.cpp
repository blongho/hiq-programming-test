#include <catch2/catch_test_macros.hpp>
#include <algorithm>

#include "TestCaseReader.h"

SCENARIO("Reading testcases from file") {
    GIVEN("A file containing test cases") {
        TestCaseReader reader;
        THEN("It should be possible to read the contents and use them as test cases") {
            try {
                reader.setTestFile("../testcase_tests.txt");
                reader.readCommand();

                const auto testCases = reader.getTestCases();

                REQUIRE(testCases.size() == 3);

                const auto &firstTestCaseFromFile = testCases.at(0);

                REQUIRE(firstTestCaseFromFile.getStartState() == Robot(Point(0, 0), Direction::NORTH));

                const std::vector<Action> actions{Action::MOVE, Action::REPORT};
                const auto firstTestCaseActions = firstTestCaseFromFile.getActions();

                REQUIRE(firstTestCaseActions.size() == 2);

                REQUIRE(std::equal(firstTestCaseActions.begin(), firstTestCaseActions.end(), actions.begin()));
                REQUIRE(firstTestCaseFromFile.getEndState() == Robot(Point(0, 1), Direction::NORTH));

                const TestCase &lastTestCaseFromFile = testCases.at(2);

                REQUIRE(lastTestCaseFromFile.getStartState() == Robot(Point(1, 2), Direction::EAST));
                REQUIRE(lastTestCaseFromFile.getEndState() == Robot(Point(3, 3), Direction::NORTH));

                const std::vector<Action> lastActions{Action::MOVE, Action::MOVE, Action::LEFT, Action::MOVE,
                                                      Action::REPORT};

                const auto lastCaseActions = lastTestCaseFromFile.getActions();

                REQUIRE(lastCaseActions.size() == 5);
                REQUIRE(std::equal(lastCaseActions.begin(), lastCaseActions.end(), lastActions.begin()));

            } catch (const std::exception &exception) {
                std::cerr << exception.what() << std::endl;
            }

        }
    }
}