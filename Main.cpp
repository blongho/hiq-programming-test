//
// Created by Longho Bernard Che on 2022-11-10.
//

#include <iostream>
#include <fstream>

#include "Point.h"
#include "Board.h"
#include "Robot.h"

#define INFO(thing...) std::cout  << thing... << '\n'

int main() {
    /*std::ofstream ofs("../data/point_written.txt");
    if (ofs) {
        INFO("Writing point to file");
        Point point{2, 3};
        ofs << point;
    } else {
        INFO("Error writing point to file");
    }

    std::ifstream _ifs("../data/point_written.txt");
    Point readPoint;
    char c{','};

    _ifs >> readPoint.x >> c >> readPoint.y;
    INFO(readPoint);*/
    Board board;

    Robot robot(Point(1, 2), Direction::EAST);
    //board.insert(robot.getPosition(), 'X');
    robot.move();
    board.insert(robot.getPosition(), 'X');
    robot.move();
    board.insert(robot.getPosition(), 'X');
    robot.left();
    board.insert(robot.getPosition(), 'X');
    robot.move();
    board.insert(robot.getPosition(), 'X');

    board.insert(robot.getPosition(), 'X');

    robot.report();
    return 0;
}


