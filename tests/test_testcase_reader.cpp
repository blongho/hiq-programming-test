#include <catch2/catch_test_macros.hpp>

#include "TestCaseReader.h"

SCENARIO("Reading testcases from file") {
    GIVEN("A file containing test cases") {
        TestCaseReader reader("../testcase_tests.txt");
        THEN("It should be possible to read the contents and used as test cases") {
            try {
                reader.readCommand();

                const auto testCases = reader.getTestCases();

                REQUIRE(testCases.size() == 3);

                const TestCase &firstTestCaseFromFile = testCases.at(0);
                REQUIRE(firstTestCaseFromFile.getStartState() == Robot({0, 0}, Direction::NORTH));
                const std::vector<Action> &actions{Action::MOVE, Action::REPORT};
                REQUIRE(firstTestCaseFromFile.getActions() == actions);
                REQUIRE(firstTestCaseFromFile.getEndState() == Robot({0, 1}, Direction::NORTH));

                const TestCase &lastTestCaseFromFile = testCases.at(2);
                REQUIRE(lastTestCaseFromFile.getStartState() == Robot({1, 2}, Direction::EAST));
                REQUIRE(lastTestCaseFromFile.getEndState() == Robot({3, 3}, Direction::NORTH));
                const std::vector<Action> &lastActions{Action::MOVE, Action::MOVE, Action::LEFT, Action::MOVE,
                                                       Action::REPORT};
                REQUIRE(lastTestCaseFromFile.getActions() == lastActions);
            } catch (const std::exception &exception) {
                std::cerr << exception.what() << std::endl;
            }

        }
    }
}