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
    }
    return "";
}
