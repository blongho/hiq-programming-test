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
            for (const auto &position: leftEdges) {
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
        THEN("it cannot move when it is at the right most edge") {
            for (const auto &position: rightEdges) {
                robot.setPosition(position);
                robot.move();
                REQUIRE(robot.getPosition() == position);
                REQUIRE(robot.getDirection() == Direction::EAST);
            }
        }
    }AND_WHEN("The robot is facing south") {
        const std::vector<Point> bottomEdges = {{0, 0},
                                                {0, 1},
                                                {0, 2},
                                                {0, 3},
                                                {0, 4}};
        Robot robot(bottomEdges.at(0), Direction::SOUTH);
        THEN("it cannot move when it at the bottom edge") {
            for (const auto &position: bottomEdges) {
                robot.setPosition(position);
                robot.move();
                REQUIRE(robot.getPosition() == position);
                REQUIRE(robot.getDirection() == Direction::SOUTH);
            }
        }
    }AND_WHEN("The robot is facing north") {
        const std::vector<Point> topEdges = {{4, 0},
                                             {4, 1},
                                             {4, 2},
                                             {4, 3},
                                             {4, 4}};
        Robot robot(topEdges.at(0), Direction::NORTH);
        THEN("it cannot move when it is at the top edge") {
            for (const auto &position: topEdges) {
                robot.setPosition(position);
                robot.move();
                REQUIRE(robot.getPosition() == position);
                REQUIRE(robot.getDirection() == Direction::NORTH);
            }
        }
    }
}

SCENARIO("Testing legal moves towards the west") {
    WHEN("The robot is not at the left edge") {
        const std::vector<Point> rightEdges = {{0, 4},
                                               {1, 4},
                                               {2, 4},
                                               {3, 4},
                                               {4, 4}};
        constexpr uint32_t maxLegalMoves{4};
        THEN("it should make a move one unit to the left") {
            for (const auto &position: rightEdges) {
                Robot robot(position, Direction::WEST);
                for (auto j = 1; j <= maxLegalMoves; j++) {
                    std::cout << "Position before move=" << robot.getPosition() << ", j=" << j << "\n";
                    robot.move();
                    std::cout << "Position after move=" << robot.getPosition() << "\n\n";
                    REQUIRE(robot.getPosition() == position.minusY(j));
                    REQUIRE(robot.getDirection() == Direction::WEST);
                }
            }
        }
    }

}

SCENARIO("Testing legal moves towards the east, no rotation") {
    WHEN("The robot is not at the right edge"){
        const std::vector<Point> leftEdges = {{0, 0},
                                              {1, 0},
                                              {2, 0},
                                              {3, 0},
                                              {4, 0}};
        constexpr uint32_t maxLegalMoves{4};
        THEN("it should make a move one unit to the right"){
            for (const auto &position: leftEdges){
                Robot robot(position, Direction::EAST);
                for(auto i = 1; i<=maxLegalMoves; ++i){
                    std::cout << "Position before move=" << robot.getPosition() << ", i=" << i << "\n";
                    robot.move();
                    std::cout << "Position after move=" << robot.getPosition() << "\n\n";
                    REQUIRE(robot.getPosition() == position.plusY(i));
                    REQUIRE(robot.getDirection() == Direction::EAST);
                }
            }
        }
    }

}

SCENARIO("Testing legal moves towards the north") {
    WHEN("The robot is not at the top edge"){
        const std::vector<Point> bottomEdges = {{0, 0},
                                                {0, 1},
                                                {0, 2},
                                                {0, 3},
                                                {0, 4}};
        constexpr uint32_t maxLegalMoves{4};
        THEN("it should make a move one unit to towards the north(top)"){
            for (const auto &position: bottomEdges){
                Robot robot(position, Direction::NORTH);
                for(auto i = 1; i<=maxLegalMoves; ++i){
                    std::cout << "Position before move=" << robot.getPosition() << ", i=" << i << "\n";
                    robot.move();
                    std::cout << "Position after move=" << robot.getPosition() << "\n\n";
                    REQUIRE(robot.getPosition() == position.plusX(i));
                    REQUIRE(robot.getDirection() == Direction::NORTH);
                }
            }
        }
    }
}

SCENARIO("Testing legal moves towards the south") {

}
