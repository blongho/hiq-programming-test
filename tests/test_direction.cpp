#include <catch2/catch_test_macros.hpp>
#include "Direction.h"

SCENARIO("Testing the Direction states") {
    GIVEN("A direction") {
        Direction direction = Direction::EAST;
        REQUIRE(direction == Direction::EAST);
        THEN("It should be possible to re-assign it to another direction") {
            direction = Direction::NORTH;
            REQUIRE(direction == Direction::NORTH);
            direction = Direction::WEST;
            REQUIRE(direction == Direction::WEST);
            direction = Direction::SOUTH;
            REQUIRE(direction == Direction::SOUTH);
        }AND_GIVEN("A string for a direction") {
            std::string north{"NORTH"};
            THEN("It should be possible to be converted to a direction") {
                REQUIRE(Direction::NORTH == ::stringToDirection(north));
                REQUIRE(Direction::SOUTH == stringToDirection("SOUTH"));
                REQUIRE(Direction::WEST == stringToDirection("WEST"));
                REQUIRE(Direction::EAST == stringToDirection("EAST"));
            }
        }AND_GIVEN("A direction") {
            Direction north = Direction::NORTH;
            Direction south = Direction::SOUTH;
            Direction west = Direction::WEST;
            Direction east = Direction::EAST;
            THEN("It can be converted to string") {
                REQUIRE("NORTH" == directionToString(north));
                REQUIRE("SOUTH" == directionToString(south));
                REQUIRE("WEST" == directionToString(west));
                REQUIRE("EAST" == directionToString(east));
            }
        }
    }
}