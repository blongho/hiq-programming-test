#include <catch2/catch_test_macros.hpp>
#include "Robot.h"
#include "Action.h"
#include "TestCaseReader.h"

SCENARIO("Testing left turns") {
    const Point origin(0, 0);
    WHEN("The robot is facing east") {
        Robot robot(origin, Direction::EAST);
        THEN("it should be facing north when turned left and it should not change coordinates") {
            robot.left();
            REQUIRE(robot.getPosition() == origin);
            REQUIRE(robot.getDirection() == Direction::NORTH);
        }
    }AND_WHEN("The robot is facing north") {
        Robot robot(origin, Direction::NORTH);
        THEN("it should be facing west when turned left and it should not change coordinates") {
            robot.left();
            REQUIRE(robot.getPosition() == origin);
            REQUIRE(robot.getDirection() == Direction::WEST);
        }
    }AND_WHEN("The robot is facing west") {
        Robot robot(origin, Direction::WEST);
        THEN("it should be facing south when turned left and it should not change coordinates") {
            robot.left();
            REQUIRE(robot.getPosition() == origin);
            REQUIRE(robot.getDirection() == Direction::SOUTH);
        }
    }AND_WHEN("The robot is facing south") {
        Robot robot(origin, Direction::SOUTH);
        THEN("it should be facing east when turned left and it should not change coordinates") {
            robot.left();
            REQUIRE(robot.getPosition() == origin);
            REQUIRE(robot.getDirection() == Direction::EAST);
        }
    }
}

SCENARIO("Testing right turns") {
    const Point origin(0, 0);
    WHEN("The robot is facing east") {
        Robot robot(origin, Direction::EAST);
        THEN("it should be facing south when turned left and it should not change coordinates") {
            robot.right();
            REQUIRE(robot.getPosition() == origin);
            REQUIRE(robot.getDirection() == Direction::SOUTH);
        }
    }AND_WHEN("The robot is facing north") {
        Robot robot(origin, Direction::NORTH);
        THEN("it should be facing east when turned left and it should not change coordinates") {
            robot.right();
            REQUIRE(robot.getPosition() == origin);
            REQUIRE(robot.getDirection() == Direction::EAST);
        }
    }AND_WHEN("The robot is facing west") {
        Robot robot(origin, Direction::WEST);
        THEN("it should be facing north when turned left and it should not change coordinates") {
            robot.right();
            REQUIRE(robot.getPosition() == origin);
            REQUIRE(robot.getDirection() == Direction::NORTH);
        }
    }AND_WHEN("The robot is facing south") {
        Robot robot(origin, Direction::SOUTH);
        THEN("it should be facing east when turned left and it should not change coordinates") {
            robot.right();
            REQUIRE(robot.getPosition() == origin);
            REQUIRE(robot.getDirection() == Direction::WEST);
        }
    }
}

SCENARIO("Testing sample known cases with combination of robot movements") {
    GIVEN("A robot at the bottom left-most region (0,0) and facing WEST") {
        Robot robot({0, 0}, Direction::WEST);
        WHEN("it is instructed to move") {
            robot.move();
            THEN("The robot will not move and the direction will remain the same") {
                REQUIRE(robot.getPosition() == Point(0, 0));
                REQUIRE(robot.getDirection() == Direction::WEST);
            }
        }
    }AND_GIVEN("A robot at origin and facing NORTH") {
        Robot robot({0, 0}, Direction::NORTH);
        WHEN("it is instructed to move") {
            robot.move();
            THEN("the robot will move one unit to the y-axis") {
                REQUIRE(robot.getPosition() == Point(0, 1));
                REQUIRE(robot.getDirection() == Direction::NORTH);
                robot.report();
            }
        }
    }AND_GIVEN("A robot from origin and pointing north") {
        Robot robot({0, 0}, Direction::NORTH);
        WHEN("it turns left") {
            robot.left();
            THEN("it should be in the same position bu the direction should change to west") {
                REQUIRE(robot.getPosition() == Point(0, 0));
                REQUIRE(robot.getDirection() == Direction::WEST);
                robot.report();
            }
        }
    }AND_GIVEN("A robot at position (1,2), facing east") {
        Robot robot({1, 2}, Direction::EAST);
        WHEN("it moves two units, turns left and makes one more move") {
            robot.move();
            robot.move();
            robot.left();
            robot.move();
            THEN("The robot should be in position (3,3) and facing NORTH") {
                REQUIRE(robot.getPosition() == Point(3, 3));
                REQUIRE(robot.getDirection() == Direction::NORTH);
                robot.report();

            }
        }
    }
}

TEST_CASE("Testing from file") {
    try {
        TestCaseReader reader;
        reader.readCommand();
        const auto testCases = reader.getTestCases();
        if (testCases.empty()) {
            std::cout << "There are no tests cases \n";
            exit(1);
        }
        for (const auto &testCase: testCases) {
            Robot robot = testCase.getStartState();
            Robot expected = testCase.getEndState();
            const auto &actions = testCase.getActions();

            for (const auto &action: actions) {
                if (action == Action::REPORT) {

                    /*std::cout << "Start state : " << testCase.getStartState()
                              << "\nEnd  stata: " << testCase.getEndState() << std::endl;*/
                    REQUIRE(robot == expected);
                }
                robot.performAction(action);

            }
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}