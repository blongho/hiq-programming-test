#include <iostream>
#include <algorithm>
#include <vector>
#include "Robot.h"

Robot::Robot(const Point &p_position, const Direction &p_direction)
        : position{p_position}, direction{p_direction} {}

void Robot::report() {
    std::cout  <<  '\n' <<position << "," << directionToString(direction) << '\n';
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



bool Robot::moveNorth() {
    std::cout << "Attempting to move north...\n";
    if (isNorthMovePossible()) {
        ++position.y;
        std::cout << "Moved to the north. Current position is (x,y) " << position << "\n";
        return true;
    }
    std::cout << "Could not move north. Robot might fall. \n";
    return false;
}

bool Robot::moveSouth() {
    std::cout << "Attempting to move south...\n";
    if (isSouthMovePossible()) {
        --position.y;
        std::cout << "Moved to the south. Current position is (x,y) " << position << "\n";
        return true;
    }
    std::cout << "Could not move south. Robot might fall. \n";

    return false;
}

bool Robot::moveEast() {
    std::cout << "Attempting to move east...\n";
    if (isEastMovePossible()) {
        ++position.x;
        std::cout << "Moved to the east. Current position is (x,y) " << position << "\n";
        return true;
    }
    std::cout << "Could not move east. Robot might fall. \n";
    return false;
}

bool Robot::moveWest() {
    std::cout << "Attempting to move west...\n";
    if (isWestMovePossible()) {
        --position.x;
        std::cout << "Moved to the west. Current position is (x,y) " << position << "\n";
        return true;
    }
    std::cout << "Could not move west. Robot might fall. \n";
    return false;
}

bool Robot::isWestMovePossible() const {
    const std::vector<Point> leftEdges = {{0, 0},
                                          {1, 0},
                                          {2, 0},
                                          {3, 0},
                                          {4, 0}};

    return std::none_of(leftEdges.cbegin(), leftEdges.cend(), [&](const auto &p) { return p == position; });
}

bool Robot::isEastMovePossible() const {
    const std::vector<Point> rightEdges = {{0, 4},
                                           {1, 4},
                                           {2, 4},
                                           {3, 4},
                                           {4, 4}};

    return std::none_of(rightEdges.cbegin(), rightEdges.cend(), [&](const auto &p) { return p == position; });
}

bool Robot::isNorthMovePossible() const {
    const std::vector<Point> topEdges = {{4, 0},
                                         {4, 1},
                                         {4, 2},
                                         {4, 3},
                                         {4, 4}};

    return std::none_of(topEdges.cbegin(), topEdges.cend(), [&](const auto &p) { return p == position; });
}

bool Robot::isSouthMovePossible() const {
    const std::vector<Point> bottomEdges = {{0, 0},
                                            {0, 1},
                                            {0, 2},
                                            {0, 3},
                                            {0, 4}};

    return std::none_of(bottomEdges.cbegin(), bottomEdges.cend(), [&](const auto &p) { return p == position; });
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
