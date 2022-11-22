#include <catch2/catch_test_macros.hpp>
#include "TestCase.h"

SCENARIO("Given a test case") {
    TestCase testCase(Robot(Point(0, 0), Direction::EAST),
                      {Action::MOVE, Action::REPORT},
                      Robot(Point(1, 0), Direction::EAST)
    );
    WHEN("The actions are executed") {
        Robot startState = testCase.getStartState();
        const Robot endState = testCase.getEndState();
        for (const auto &action: testCase.getActions()) {
            startState.performAction(action);
        }
        REQUIRE(startState.getDirection() == endState.getDirection());
        REQUIRE(startState.getPosition() == endState.getPosition());
    }AND_WHEN("The start state is changed") {
        const Robot tmpState(Point(2, 2), Direction::NORTH);
        testCase.setStartState(tmpState);
        THEN("The testcase's start state is also changed") {
            REQUIRE(testCase.getStartState() == tmpState);
        }
    }AND_WHEN("The end state is changed") {
        const Robot endState(Point(3, 0), Direction::EAST);
        testCase.setEndState(endState);
        THEN("The test case's end state is changed") {
            REQUIRE(testCase.getEndState() == endState);
        }
    }AND_WHEN("The actions are changed") {
        const std::vector<Action> actions{Action::MOVE, Action::LEFT, Action::REPORT};
        testCase.setActions(actions);
        THEN("The test case's actions are changed") {
            REQUIRE(testCase.getActions() == actions);
        }
    }
}