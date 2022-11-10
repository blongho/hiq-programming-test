//
// Created by Longho Bernard Che on 2022-11-10.
//

#include <iostream>
#include <fstream>

#include "Point.h"
#include "Board.h"

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
    board.insert({0,0}, 'x');
    
    board.insert({1,0}, 'Y');
    
    board.insert({4,4}, 'e');
    
    return 0;
}


