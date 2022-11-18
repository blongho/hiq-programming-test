#include <iostream>
#include <algorithm>
#include <vector>
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
    if (x < 0 || y < 0 || x > 4 || y > 4) return;
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
    std::cout << "Attempting to move north...\n";
    if (isNorthMovePossible()) {
        ++position.y;
        std::cout << "Moved to the north. Current position is (x,y) " << position << "\n";
        show();
    }
    std::cout << "Could not move north. Robot might fall. \n";
}

void Robot::moveSouth() {
    std::cout << "Attempting to move south...\n";
    if (isSouthMovePossible()) {
        --position.y;
        std::cout << "Moved to the south. Current position is (x,y) " << position << "\n";
        show();
    }
    std::cout << "Could not move south. Robot might fall. \n";
}

void Robot::moveEast() {
    std::cout << "Attempting to move east...\n";
    if (isEastMovePossible()) {
        ++position.x;
        std::cout << "Moved to the east. Current position is (x,y) " << position << "\n";
        show();
    }
    std::cout << "Could not move east. Robot might fall. \n";
}

void Robot::moveWest() {
    std::cout << "Attempting to move west...\n";
    if (isWestMovePossible()) {
        --position.x;
        std::cout << "Moved to the west. Current position is (x,y) " << position << "\n";
        show();
    }
    std::cout << "Could not move west. Robot might fall. \n";
}

bool Robot::isWestMovePossible() const {
    return (position.x - 1) >= 0;
}

bool Robot::isEastMovePossible() const {
    return (position.x + 1) < 5;
}

bool Robot::isNorthMovePossible() const {
    return (position.y + 1) < 5;
}

bool Robot::isSouthMovePossible() const {
    return (position.y - 1) >= 0;
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
    os << robot.getPosition().x << "," << robot.getPosition().y << "," << directionToString(robot.getDirection());
    return os;
}

bool Robot::operator==(const Robot &rhs) const {
    return position == rhs.position &&
           direction == rhs.direction;
}

bool Robot::operator!=(const Robot &rhs) const {
    return !(rhs == *this);
}

