
#include "Robot.h"

Robot::Robot(const Point &p_position, const Direction &p_direction)
        : position{p_position}, direction{p_direction} {}

void Robot::report() {
    std::cout << "Robot [" << *this << "]\n";
    show();
    std::cout << "\n";
}

const Point &Robot::getPosition() const {
    return position;
}

const Direction &Robot::getDirection() const {
    return direction;
}

void Robot::left() {
    if (!isRobotOnTheTable()) {
        std::cerr << "Robot is not on the table. Left turn not possible!\n";
        return;
    }
    switch (direction) {
        case Direction::NORTH:
            direction = Direction::WEST;
            break;
        case Direction::SOUTH:
            direction = Direction::EAST;
            break;
        case Direction::EAST:
            direction = Direction::NORTH;
            break;
        case Direction::WEST:
            direction = Direction::SOUTH;
            break;
        case Direction::NONE:
            break;
    }
    show();
}

void Robot::move() {
    if (!isRobotOnTheTable()) {
        std::cerr << "Cannot make a move on a robot that is not on the table!\n";
        return;
    }
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
        case Direction::NONE:
            break;
    }
    show();
}

void Robot::right() {
    if (!isRobotOnTheTable()) {
        std::cerr << "Robot is not on the table. Right turn not possible!\n";
        return;
    }
    switch (direction) {
        case Direction::NORTH:
            direction = Direction::EAST;
            break;
        case Direction::SOUTH:
            direction = Direction::WEST;
            break;
        case Direction::EAST:
            direction = Direction::SOUTH;
            break;
        case Direction::WEST:
            direction = Direction::NORTH;
            break;
        case Direction::NONE:
            break;
    }
    show();
}


void Robot::moveNorth() {
    std::cout << "\nAttempting to move north. State: " << *this << "\n";
    if (isNorthMovePossible()) {
        ++position.y;
        std::cout << "Moved to the north. State: " << *this << "\n";
    }
}

void Robot::moveSouth() {
    std::cout << "\nAttempting to move south...\n";
    if (isSouthMovePossible()) {
        --position.y;
        std::cout << "Moved to the south. State: " << *this << "\n";
    }
}

void Robot::moveEast() {
    std::cout << "\nAttempting to move east. State: " << *this << "\n";
    if (isEastMovePossible()) {
        ++position.x;
        std::cout << "Moved to the east. State: " << *this << "\n";
    }
}

void Robot::moveWest() {
    std::cout << "\nAttempting to move west. State: " << *this << "\n";
    if (isWestMovePossible()) {
        --position.x;
        std::cout << "Moved to the west. State: " << *this << "\n";
    }
}

bool Robot::isWestMovePossible() const {
    if (!isRobotOnTheTable()) {
        std::cerr << "Robot is not on the table. Move not possible!\n";
        return false;
    }
    if ((position.x - 1) < Point::min()) {
        std::cerr << "Robot will fall if this move is made. State: " << *this << std::endl;
        return false;
    }
    return true;
}

bool Robot::isEastMovePossible() const {
    if (!isRobotOnTheTable()) {
        std::cerr << "Robot is not on the table. Move not possible!\n";
        return false;
    }
    if ((position.x + 1) > Point::max()) {
        std::cerr << "Robot will fall if this move is made. State: " << *this << std::endl;
        return false;
    }
    return true;
}

bool Robot::isNorthMovePossible() const {
    if (!isRobotOnTheTable()) {
        std::cerr << "Robot is not on the table. Move not possible!\n";
        return false;
    }
    if ((position.y + 1) > Point::max()) {
        std::cerr << "Robot will fall if this move is made. State: " << *this << std::endl;
        return false;
    }
    return true;
}

bool Robot::isSouthMovePossible() const {
    if (!isRobotOnTheTable()) {
        std::cerr << "Robot is not on the table. Move not possible!\n";
        return false;
    }
    if ((position.y - 1) < Point::min()) {
        std::cerr << "Robot will fall if this move is made. State: " << *this << std::endl;
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
            arrow = "R!";
            break;
        case Direction::EAST:
            arrow = "R->";
            break;
        case Direction::WEST:
            arrow = "<-R";
            break;
        case Direction::NONE:
            arrow = "";
            break;
    }

    board.update(position, arrow);
}

bool Robot::operator==(const Robot &rhs) const {
    return position == rhs.position &&
           direction == rhs.direction;
}

bool Robot::isRobotOnTheTable() const {
    return position.isValid();
}

void Robot::performAction(const Action &action) {
    switch (action) {
        case Action::MOVE:
            move();
            break;
        case Action::LEFT:
            left();
            break;
        case Action::RIGHT:
            right();
            break;
        case Action::REPORT:
            report();
            break;
        case Action::NONE:
            // do nothing
            break;
    }

}

std::ostream &operator<<(std::ostream &os, const Robot &robot) {
    const auto [x, y] = robot.getPosition();
    os << x << "," << y << "," << directionToString(robot.getDirection());
    return os;
}


