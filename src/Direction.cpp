//
// Created by bernard.c.longho on 2022-11-15.
//
#include "Direction.h"


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
            return "";
    }
}

Direction stringToDirection(const std::string &direction) {
    if (direction == "NORTH") {
        return Direction::NORTH;
    } else if (direction == "SOUTH") {
        return Direction::SOUTH;
    } else if (direction == "WEST") {
        return Direction::WEST;
    } else {
        return Direction::EAST;
    }
}
