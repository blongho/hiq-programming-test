//
// Created by bernard.c.longho on 2022-11-10.
//

#include "Robot.h"
#include <iostream>

void Robot::report(std::ostream &os) {
    os << position.x << "," << position.y << "," << directionToString(direction);
}

const Point &Robot::getPosition() const {
    return position;
}

void Robot::setPosition(const Point &p_position) {
    position = p_position;
}

const Direction &Robot::getDirection() const {
    return direction;
}

void Robot::setDirection(Direction p_direction) {
    direction = p_direction;
}

void Robot::left() {
    if (direction == Direction::NORTH) {
        direction = Direction::WEST;
    } else if (direction == Direction::WEST) {
        direction = Direction::SOUTH;
    } else if (direction == Direction::SOUTH) {
        direction = Direction::WEST;
    } else if (direction == Direction::EAST) {
        direction = Direction::NORTH;
    }
}

bool Robot::move() {
    switch (direction) {
        case Direction::NORTH:
            return moveNorth();
        case Direction::SOUTH:
            return moveSouth();
        case Direction::EAST:
            return moveEast();
        case Direction::WEST:
            return moveWest();
        default:
            return false;
    }
}

void Robot::right() {
    if (direction == Direction::NORTH) {
        direction = Direction::EAST;
    } else if (direction == Direction::WEST) {
        direction = Direction::NORTH;
    } else if (direction == Direction::SOUTH) {
        direction = Direction::WEST;
    } else if (direction == Direction::EAST) {
        direction = Direction::SOUTH;
    }
}

bool Robot::isMovePossible() const {
    const auto x{position.x};
    const auto y{position.y};
    return x >= 0 || y >= 0 || x <= 4 || y <= 4 || (x + 1) <= 4 || (y + 1) <= 4 || (x - 1) >= 0 || (y - 1) >= 0;
}

Robot::Robot(const Point &p_position, const Direction &p_direction)
        : position{p_position}, direction{p_direction} {}

bool Robot::moveNorth() {
    std::cout << "Moving to the north\n";
    if (isMovePossible()) {
        if ((position.y + 1) > 4) {
            std::cout << "Move not possible! Robot will fall\n";
            return false;
        }
        ++position.y;
        std::cout << "Moved to the north\n";
        return true;
    }
    std::cout << "Not possible to make this move\n";
    return false;
}

bool Robot::moveSouth() {
    std::cout << "Moving to the south...\n";
    if (isMovePossible()) {
        if ((position.y - 1) >= 0) {
            std::cout << "Could not move to the south\n";
            return false;
        }
        --position.y;
        std::cout << "Moved to the south " << position << "\n\n";
        return true;
    }
    return false;
}

bool Robot::moveEast() {
    std::cout << "Moving to the east...\n";
    if (isMovePossible()) {
        if ((position.x + 1) > 4) {
            std::cout << "Could not move to the east\n";
            return false;
        }
        ++position.x;
        std::cout << "Moved to the east " << position << "\n\n";
        return true;
    }
    return false;
}

bool Robot::moveWest() {
    std::cout << "Moving to the west...\n";
    if (isMovePossible()) {
        if ((position.x - 1) >= 0) {
            std::cout << "Could not move to the west\n";
            return false;
        }
        --position.x;
        std::cout << "Moved to the west " << position << "\n\n";
        return true;
    }
    return false;
}
