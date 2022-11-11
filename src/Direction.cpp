#include "Direction.h"

std::ostream &operator<<(std::ostream &os, const Direction &direction) {
    switch (direction) {
        case Direction::NORTH:
            os << "NORTH";
            break;
        case Direction::SOUTH:
            os << "SOUTH";
            break;
        case Direction::EAST:
            os << "EAST";
            break;
        case Direction::WEST:
            os << "WEST";
            break;
    }
    return os;
}

std::istream &operator>>(std::istream &is, Direction &direction) {
    std::string tmp{};
    is >> tmp;
    if (tmp == "NORTH") {
        direction = Direction::NORTH;
    } else if (tmp == "SOUTH") {
        direction = Direction::SOUTH;
    } else if (tmp == "EAST") {
        direction = Direction::EAST;
    } else if (tmp == "WEST") {
        direction = Direction::WEST;
    }
    return is;
}