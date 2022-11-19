#ifndef HIQ_PROGRAMMING_DIRECTION_H
#define HIQ_PROGRAMMING_DIRECTION_H

#include <string>

enum class Direction {
    NORTH,
    SOUTH,
    EAST,
    WEST,
    NONE
};

std::string directionToString(const Direction &direction);

Direction stringToDirection(const std::string &direction);

#endif //HIQ_PROGRAMMING_DIRECTION_H
