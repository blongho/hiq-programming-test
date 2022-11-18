#include <iostream>
#include <algorithm>
#include "Robot.h"

Robot::Robot(const Point &p_position, const Direction &p_direction)
        : position{p_position}, direction{p_direction} {}

void Robot::report() {
    std::cout << '\n' << position << "," << directionToString(direction) << '\n';
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
        direction = Direction::EAST;
    } else {
        direction = Direction::NORTH;
    }
}

void Robot::move() {
    const auto [x, y] = position;
    if (!isRobotOnTheTable()) return;

    switch (direction) {
        case Direction::NORTH:
            moveNorth();
            break;
        case Direction::SOUTH:
            moveSouth();
            break;
        case Direction::EAST:
            moveEast();
            break;
        case Direction::WEST:
            moveWest();
            break;
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


void Robot::moveNorth() {
    std::cout << "Attempting to move north. State: " << *this << std::endl;
    if (isNorthMovePossible()) {
        ++position.y;
        std::cout << "Moved to the north. State: " << *this << "\n";
        show();
    }
}

void Robot::moveSouth() {
    std::cout << "Attempting to move south...\n";
    if (isSouthMovePossible()) {
        --position.y;
        std::cout << "Moved to the south. State: " << *this << "\n";
        show();
    }
}

void Robot::moveEast() {
    std::cout << "Attempting to move east. State: " << *this << "\n";
    if (isEastMovePossible()) {
        ++position.x;
        std::cout << "Moved to the east. State: " << *this << "\n";
        show();
    }
}

void Robot::moveWest() {
    std::cout << "Attempting to move west. State: " << *this << "\n";
    if (isWestMovePossible()) {
        --position.x;
        std::cout << "Moved to the west. State: " << *this << "\n";
        show();
    }
}

bool Robot::isWestMovePossible() const {
    if (!isRobotOnTheTable()) {
        std::cout << "Robot is not on the table. Move not possible!\n";
        return false;
    }
    if ((position.x - 1) < 0) {
        std::cout << "Robot will fall if this move is made. State: " << *this << std::endl;
        return false;
    }
    return true;
}

bool Robot::isEastMovePossible() const {
    if (!isRobotOnTheTable()) {
        std::cout << "Robot is not on the table. Move not possible!\n";
        return false;
    }
    if ((position.x + 1) > 4) {
        std::cout << "Robot will fall if this move is made. State: " << *this << std::endl;
        return false;
    }
    return true;
}

bool Robot::isNorthMovePossible() const {
    if (!isRobotOnTheTable()) {
        std::cout << "Robot is not on the table. Move not possible!\n";
        return false;
    }
    if ((position.y + 1) > 4) {
        std::cout << "Robot will fall if this move is made. State: " << *this << std::endl;
        return false;
    }
    return true;
}

bool Robot::isSouthMovePossible() const {
    if (!isRobotOnTheTable()) {
        std::cout << "Robot is not on the table. Move not possible!\n";
        return false;
    }
    if ((position.y - 1) < 0) {
        std::cout << "Robot will fall if this move is made. State: " << *this << std::endl;
        return false;
    }
    return true;
}

void Robot::show() const {
    Board board;
    std::string arrow{};
    switch (direction) {

        case Direction::NORTH:
            arrow = "R^";
            break;
        case Direction::SOUTH:
            arrow = "R↓";
            break;
        case Direction::EAST:
            arrow = "R->";
            break;
        case Direction::WEST:
            arrow = "<-R";
            break;
    }

    board.insert(position, arrow);
    board.show();

}

std::ostream &operator<<(std::ostream &os, const Robot &robot) {
    const auto [x, y] = robot.getPosition();
    os << x << "," << y << "," << directionToString(robot.getDirection());
    return os;
}

bool Robot::operator==(const Robot &rhs) const {
    return position == rhs.position &&
           direction == rhs.direction;
}

bool Robot::operator!=(const Robot &rhs) const {
    return !(rhs == *this);
}

bool Robot::isRobotOnTheTable() const {
    const auto [x, y] = position;
    return (x >= 0 && x <= 4 && y >= 0 && y <= 4);
}

