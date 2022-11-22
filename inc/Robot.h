/**
 * @file Robot.h
 * @brief The Robot. It has its position and direction
 * @author Longho Bernard Che
 */
#ifndef HIQ_PROGRAMMING_ROBOT_H
#define HIQ_PROGRAMMING_ROBOT_H

#include <iostream>

#include "Board.h"
#include "Direction.h"
#include "Action.h"

/**
 * \class Robot
 * @brief The Robot. It has its position and direction
 */
class Robot {
public:
    /**
     * @brief The default constructor
     * Positions the robot at {0,0,NONE}
     */
    explicit Robot() = default;

    /**
     * @brief Construct a robot and initialize all its data members
     * @param p_position the robot's position
     * @param p_direction the direction hat the robot is facing
     */
    explicit Robot(const Point &p_position, const Direction &p_direction);

    /**
     * @brief Move the robot one unit forward in the direction it is currently facing
     * <br><br>
     * A move is only possible if the following are met
     * <ul>
     * <li>The robot is on the table </li>
     * <li>The move will not result in the robot falling off the table </li>
     * </ul>
     */
    void move();

    /**
     * @brief Rotate the robot 90 degrees right
     * <br><br>
     * This will be ignored if the robot is not on the table
     */
    void right();

    /**
     * @brief Rotate the robot 90 degrees left
     * <br><br>
     * This will be ignored if the robot is not on the talbe
     */
    void left();

    /**
     * @brief Announce the X,Y and F of the robot. Also shows a 5x5 board with R(direction_arrow) depicting the location
     * and direction of the robot
     */
    void report();

    /**
     * @brief Get the current position of the Robot
     * @return the robot's position
     */
    [[nodiscard]] const Point &getPosition() const;

    /**
     * @brief Get the current direction that robot
     * @return  the robot's direction @see Direction
     */
    [[nodiscard]] const Direction &getDirection() const;


    /**
     * @brief Checks if two robots have the same states
     * @param rhs the other robot
     * @return true if the direction and position of the robot are equal
     */
    bool operator==(const Robot &rhs) const;


    /**
     * @brief Perform an action
     * @param action the action to be performed
     */
    void performAction(const Action &action);

    /**
     * Destructor
     */
    ~Robot() = default;

    friend std::ostream &operator<<(std::ostream &os, const Robot &robot);

private:
    Point position{}; //!< the robot's position
    Direction direction{Direction::NONE}; //!< The direction that the robot is facing

    /**
     * Make a one step move towards the north (up). <br>Increases the position of the robot one unit towards the y-axis
     */
    void moveNorth();

    /**
     * @brief Make a one step move towards the south (down). <br>Decreases the position of the robot one unit in the
     * y-axis <br>
     * <br>
     * Pre-condition<br>
     * The robot is on the table and not at the bottom <br>
     * <br>
     * Post-condition <br>
     * The robot's position is decreased by 1 unit in the y-axis
     */
    void moveSouth();

    /**
     * @brief Make a one step move towards the east (right). <br>Increases the position of the robot one unit in the
     * x-axis <br>
     *<br>
     * Pre-condition<br>
     * The robot is on the table and not at the edge right edge<br>
     *<br>
     * Post-condition<br>
     * The robot's position is increased by 1 unit in the x-axis
     */
    void moveEast();

    /**
     * @brief Make a one step move towards the west (left). <br>Decreases the position of the robot by one unit in the
     * x-axis <br>
     *
     * <br>
     * Pre-condition <br>
     * The robot is on the table and the robot is not at the left edge <br>
     * <br>
     * Post-condition <br>
     * The robot's position is decreased by 1 unit in the x-axis
     *
     */
    void moveWest();

    /**
     * @brief Check if it is possible to make a move towards the west<br>
     * A move is possible if the robot is on the table and the robot will not fall if it made the move
     * @return true if the move is possible, otherwise false
     */
    [[nodiscard]] bool isWestMovePossible() const;

    /**
    * @brief Check if it is possible to make a move towards the east<br>
    * A move is possible if the robot is on the table and the robot will not fall if it made the move
    * @return true if the move is possible, otherwise false
    */
    [[nodiscard]] bool isEastMovePossible() const;

    /**
    * @brief Check if it is possible to make a move towards the north<br>
    * A move is possible if the robot is on the table and the robot will not fall if it made the move
    * @return true if the move is possible, otherwise false
    */
    [[nodiscard]] bool isNorthMovePossible() const;

    /**
    * @brief Check if it is possible to make a move towards the south<br>
    * A move is possible if the robot is on the table and the robot will not fall if it made the move
    * @return true if the move is possible, otherwise false
    */
    [[nodiscard]] bool isSouthMovePossible() const;

    /**
     * @brief Check if the robot is on the table or not
     * @return true if the robot is on the table, otherwise false
     */
    [[nodiscard]] bool isRobotOnTheTable() const;


    /**
     * @brief Shows a 5x5 layout of the robot
     */
    void show() const;
};

#endif //HIQ_PROGRAMMING_ROBOT_H
