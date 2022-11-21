#include <catch2/catch_test_macros.hpp>
#include "Point.h"

SCENARIO("Testing point behaviour") {
    WHEN("A point is initialized without any values for x and y") {
        Point point;
        THEN("The values of x and y are equal and both zero") {
            REQUIRE(point.x == 0);
            REQUIRE(point.y == 0);
            REQUIRE(point.x == point.y);
        }AND_THEN("The values of x and y can vary independently") {
            point.x = 5;
            point.y = 6;
            REQUIRE_FALSE(point.x == point.y);
            REQUIRE(point.x == 5);
            REQUIRE(point.y == 6);
        }
    }
}

SCENARIO("A point is given that is out of the table"){
    WHEN("A point has negative values"){
        Point point(5, 0);
        THEN("It should evaluate as invalid"){
            REQUIRE_FALSE(point.isValid());
        }
    }

}

SCENARIO("Testing equality of two points"){
    WHEN("A point is initialized"){
        Point point(1,2);
        THEN("It can be compared to another point"){
            REQUIRE(point == Point(1,2));
            REQUIRE_FALSE(Point(0,0) == Point(1,0));
        }
    }
}
