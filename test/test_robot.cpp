//
// Created by Longho Bernard Che on 2022-11-10.
//
#include <catch2/catch_test_macros.hpp>
#include "Robot.h"

SCENARIO("The robot will not move when at the edge") {
    WHEN("The robot is facing west") {
        THEN("it cannot move when x==0") {
            const Point origin(0, 0);
            const Direction west = Direction::WEST;
            Robot robot(origin, west);
            robot.move();
            REQUIRE(robot.getPosition() == origin);
            REQUIRE(robot.getDirection() == Direction::WEST);
            robot.show();
            // The robot will not move west at (1,0)
            robot.setPosition({1, 0});
            robot.show();
            robot.move();
            REQUIRE(robot.getPosition() == Point(1, 0));
            REQUIRE(robot.getDirection() == Direction::WEST);

            // the robot should not move when at (0,2)
            const Point point2(2, 0);
            robot.setPosition(point2);
            robot.show();
            robot.move();
            REQUIRE(robot.getPosition() == point2);
            REQUIRE(robot.getDirection() == Direction::WEST);
            // the robot should not move when at (0,3)
            const Point point3(3, 0);
            robot.setPosition(point3);
            robot.show();
            robot.move();

            REQUIRE(robot.getPosition() == point3);
            REQUIRE(robot.getDirection() == Direction::WEST);
            // the robot should not move when at (0,4)
            const Point point4(4, 0);
            robot.setPosition(point4);
            robot.move();
            REQUIRE(robot.getPosition() == point4);
            REQUIRE(robot.getDirection() == Direction::WEST);
            robot.show();

        }
    }AND_WHEN("The robot is facing east") {
        const std::vector<Point> rightEdges = {{0, 4},
                                               {1, 3},
                                               {2, 2},
                                               {3, 1},
                                               {4, 0}};
        THEN("it cannot move when it is at the right most edge"){
            const Direction east = Direction::EAST;
            Robot robot(rightEdges.at(0), east);
            robot.move();
            REQUIRE(robot.getPosition() == rightEdges.at(0));
            REQUIRE(robot.getDirection() == Direction::EAST);
            robot.show();
        }
    }
}
