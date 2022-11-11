//
// Created by Longho Bernard Che on 2022-11-10.
//

#ifndef HIQ_PROGRAMMING_DIRECTION_H
#define HIQ_PROGRAMMING_DIRECTION_H
#include <iostream>
enum class Direction {
    NORTH = 0,
    SOUTH,
    EAST,
    WEST
};

std::ostream &operator<<(std::ostream &os, const Direction &point);

std::istream &operator>>(std::istream &is, Direction &point);
#endif //HIQ_PROGRAMMING_DIRECTION_H
