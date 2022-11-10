//
// Created by Longho Bernard Che on 2022-11-10.
//

#ifndef HIQ_PROGRAMMING_DIRECTION_H
#define HIQ_PROGRAMMING_DIRECTION_H
#include <string>
enum class Direction {
    NORTH = 0,
    SOUTH,
    EAST,
    WEST
};

std::string directionToString(const Direction &);
#endif //HIQ_PROGRAMMING_DIRECTION_H
