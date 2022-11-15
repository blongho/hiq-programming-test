//
// Created by bernard.c.longho on 2022-11-10.
//

#ifndef HIQ_PROGRAMMING_ROBOT_H
#define HIQ_PROGRAMMING_ROBOT_H

#include "Board.h"
#include "Direction.h"

class Robot {
public:
    Robot() = default;

    Robot(const Point &p_position, const Direction &p_direction);

    bool move();

    void right();

    void left();

    void report();

    [[nodiscard]] const Point &getPosition() const;

    void setPosition(const Point &p_position);

    [[nodiscard]] const Direction &getDirection() const;

    void setDirection(Direction direction);

    void show() const;

private:
    Point position{};
    Direction direction{Direction::WEST};

    /**
     * Check if a move is possible or not
     * A move is not possible if the current robot position is outside of the table <br>
     * A move is also not possible if the next move results in the robot falling off the table
     * @return true if the move is possible, otherwise vale
     */

    bool moveNorth();

    bool moveSouth();

    bool moveEast();

    bool moveWest();

    [[nodiscard]] bool isWestMovePossible() const;

    [[nodiscard]] bool isEastMovePossible() const;

    [[nodiscard]] bool isNorthMovePossible() const;

    [[nodiscard]] bool isSouthMovePossible() const;
};




#endif //HIQ_PROGRAMMING_ROBOT_H
