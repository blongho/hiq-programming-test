#ifndef HIQ_PROGRAMMING_ROBOT_H
#define HIQ_PROGRAMMING_ROBOT_H

#include "Board.h"
#include "Direction.h"

class Robot {
public:
    Robot() = default;

    Robot(const Point &p_position, const Direction &p_direction);

    void move();

    void right();

    void left();

    void report();

    [[nodiscard]] const Point &getPosition() const;

    void setPosition(const Point &p_position);

    [[nodiscard]] const Direction &getDirection() const;

    [[maybe_unused]] void setDirection(Direction direction);

    void show() const;

    bool operator==(const Robot &rhs) const;

    bool operator!=(const Robot &rhs) const;

    void performAction(const std::string &action);

private:
    Point position{};
    Direction direction{};

    /**
     * Make a one step move towards the north (up). <br>Increases the position of the robot one unit towards the y-axis
     */
    void moveNorth();

    /**
     * Make a one step move towards the south (down). <br>Decreases the position of the robot one unit in the y-axis <br>
     *
     * Pre-condition<br>
     * The robot is on the table and not at the bottom <br>
     *
     * Post-condition <br>
     * The robot's position is decreased by 1 unit in the y-axis
     */
    void moveSouth();

    /**
     * Make a one step move towards the east (right). <br>Increases the position of the robot one unit in the x-axis <br>
     *
     * Pre-condition<br>
     * The robot is on the table and not at the edge right edge<br>
     *
     * Post-condition<br>
     * The robot's position is increased by 1 unit in the x-axis
     */
    void moveEast();

    /**
     * Make a one step move towards the west (left). <br>Decreases the position of the robot by one unit in the x-axis <br>
     *
     * Pre-condition <br>
     * The robot is on the table and the robot is not at the left edge <br>
     *
     * Post-condition <br>
     * The robot's position is decreased by 1 unit in the x-axis
     */
    void moveWest();

    /**
     * Check if it is possible to make a move towards the west<br>
     * A move is possible if the robot is on the table and the robot will not fall if it made the move
     * @return true if the move is possible, otherwise false
     */
    [[nodiscard]] bool isWestMovePossible() const;

    /**
    * Check if it is possible to make a move towards the east<br>
    * A move is possible if the robot is on the table and the robot will not fall if it made the move
    * @return true if the move is possible, otherwise false
    */
    [[nodiscard]] bool isEastMovePossible() const;

    /**
    * Check if it is possible to make a move towards the north<br>
    * A move is possible if the robot is on the table and the robot will not fall if it made the move
    * @return true if the move is possible, otherwise false
    */
    [[nodiscard]] bool isNorthMovePossible() const;

    /**
    * Check if it is possible to make a move towards the south<br>
    * A move is possible if the robot is on the table and the robot will not fall if it made the move
    * @return true if the move is possible, otherwise false
    */
    [[nodiscard]] bool isSouthMovePossible() const;

    /**
     * Check if the robot is on the table or not
     * @return true if the robot is on the table, otherwise false
     */
    [[nodiscard]] bool isRobotOnTheTable() const;

    friend std::ostream &operator<<(std::ostream &os, const Robot &robot);

};

#endif //HIQ_PROGRAMMING_ROBOT_H
