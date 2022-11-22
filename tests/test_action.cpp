#include <catch2/catch_test_macros.hpp>

#include "Action.h"

TEST_CASE("Testing an action states") {
    GIVEN("An action") {
        Action action = Action::REPORT;
        THEN("It can be re-assigned to another action") {
            action = Action::MOVE;
            REQUIRE(action == Action::MOVE);
            action = Action::LEFT;
            REQUIRE(action == Action::LEFT);
        }
    }AND_GIVEN("A string") {
        THEN("It can be converted to action") {
            const std::string action{"REPORT"};
            REQUIRE(actionFromString(action) == Action::REPORT);
            REQUIRE(actionFromString("MOVE") == Action::MOVE);
            REQUIRE(actionFromString("LEFT") == Action::LEFT);
            REQUIRE(actionFromString("RIGHT") == Action::RIGHT);
            REQUIRE(actionFromString("") == Action::NONE);

        }
    }
}