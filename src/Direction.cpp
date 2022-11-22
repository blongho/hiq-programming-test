#include "Direction.h"

#include <algorithm>

std::string directionToString(const Direction &direction) {
    switch (direction) {
        case Direction::NORTH:
            return "NORTH";
        case Direction::SOUTH:
            return "SOUTH";
        case Direction::EAST:
            return "EAST";
        case Direction::WEST:
            return "WEST";
        default:
            return "NONE";
    }
}

Direction stringToDirection(const std::string &direction) {
    std::string upperDirection{};

    std::transform(direction.begin(), direction.end(), upperDirection.begin(), ::toupper);

    if (upperDirection == "NORTH") {
        return Direction::NORTH;
    } else if (upperDirection == "SOUTH") {
        return Direction::SOUTH;
    } else if (upperDirection == "WEST") {
        return Direction::WEST;
    } else if (upperDirection == "EAST") {
        return Direction::EAST;
    } else {
        return Direction::NONE;
    }
}
