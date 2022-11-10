//
// Created by Longho Bernard Che on 2022-11-10.
//
#include <catch2/catch_test_macros.hpp>
#include "Point.h"
#include <fstream>

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

SCENARIO("Reading and writing a point to and from file") {
    WHEN("Reading a point from file"){
        THEN("We should get the values correctly"){
            std::ifstream ifs("../../data/point.txt");
            if (ifs) {
                INFO("Able to read points file");
                Point p;
                char c{','};
                ifs >> p.x >> c >> p.y;

                REQUIRE(p.x == 4);
                REQUIRE(p.y == 1);
            } else {
                WARN("Testing reading point content failed because the contents could not be read!");
            }
        }AND_WHEN("Writing to file, we should write in a similar fashion as it was when reading"){
            std::ofstream ofs("../../data/point_written.txt");
            if(ofs){
                INFO("Writing point to file");
                Point point{2,3};
                ofs << point;

                std::ifstream _ifs("../../data/point_written.txt");
                Point readPoint;
                char c{','};

                _ifs >> readPoint.x >> c >> readPoint.y;
                REQUIRE(readPoint.x == 2);
                REQUIRE(readPoint.y == 3);
            }else{
                WARN("Error writing point to file");
            }
        }
    }


}
