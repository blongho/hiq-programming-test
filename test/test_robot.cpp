//
// Created by Longho Bernard Che on 2022-11-10.
//
#include <catch2/catch_test_macros.hpp>
#include "Robot.h"

SCENARIO("The robot will not move when at the edge") {
    WHEN("The robot is facing west") {
        const std::vector<Point> leftEdges = {{0, 0},
                                              {1, 0},
                                              {2, 0},
                                              {3, 0},
                                              {4, 0}};
        Robot robot(leftEdges.at(0), Direction::WEST);
        THEN("it cannot move when at the left edge") {
            for (const auto &position: leftEdges){
                robot.setPosition(position);
                robot.move();
                REQUIRE(robot.getPosition() == position);
                REQUIRE(robot.getDirection() == Direction::WEST);
            }
        }
    }AND_WHEN("The robot is facing east") {
        const std::vector<Point> rightEdges = {{0, 4},
                                               {1, 3},
                                               {2, 2},
                                               {3, 1},
                                               {4, 0}};
        Robot robot(rightEdges.at(0), Direction::EAST);
        THEN("it cannot move when it is at the right most edge"){
            for (const auto &position: rightEdges){
                robot.setPosition(position);
                robot.move();
                REQUIRE(robot.getPosition() == position);
                REQUIRE(robot.getDirection() == Direction::EAST);
            }
        }
    }AND_WHEN("The robot is facing south"){
        const std::vector<Point> bottomEdges = {{0, 0},
                                                {0, 1},
                                                {0, 2},
                                                {0, 3},
                                                {0, 4}};
        Robot robot(bottomEdges.at(0), Direction::SOUTH);
        THEN("it cannot move when it at the bottom edge"){
            for (const auto &position: bottomEdges){
                robot.setPosition(position);
                robot.move();
                REQUIRE(robot.getPosition() == position);
                REQUIRE(robot.getDirection() == Direction::SOUTH);
            }
        }
    }AND_WHEN("The robot is facing north"){
        const std::vector<Point> topEdges = {{4, 0},
                                             {4, 1},
                                             {4, 2},
                                             {4, 3},
                                             {4, 4}};
        Robot robot(topEdges.at(0), Direction::NORTH);
        THEN("it cannot move when it is at the top edge"){
            for (const auto &position: topEdges){
                robot.setPosition(position);
                robot.move();
                REQUIRE(robot.getPosition() == position);
                REQUIRE(robot.getDirection() == Direction::NORTH);
            }
        }
    }
}
