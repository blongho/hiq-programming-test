#ifndef HIQ_PROGRAMMING_DIRECTION_H
#define HIQ_PROGRAMMING_DIRECTION_H
/**
 * @file Direction.cpp
 * @brief Holds the different directions that a robot can assume
 */
#include <string>

/**
 * \enum Direction
 * @brief The different possible directions that a robot might take
 * @code
 * Direction::NORTH // for north or up direction
 * Direction::SOUTH // for south or down direction
 * Direction::EAST // for east or right direction
 * Direction::WEST // for west of left direction
 * Direction::NONE // the robot is not on the table
 * @endcode
 */
enum class Direction {
    NORTH, //!< The robot is facing upwards
    SOUTH, //!<  The robot is facing downwards
    EAST, //!<  The robot is facing right
    WEST, //!<  The robot is facing left
    NONE //!<  The robot is not on the table
};

/**
 * @brief Get the string representation of a \link Direction
 * @param direction The Direction
 * @return a string representing the direction
 * @code
 * Usage:
 * directionToString(Direction::NORTH); // outputs "NORTH"
 * @endcode
 */
std::string directionToString(const Direction &direction);

/**
 * @brief Get a Direction from a string value
 * @param direction the direction as a string
 * @return one of Direction values
 * Usage
 * @code
 * stringToDirection("NORTH"); // outputs DIRECTION::NORTH
 * @endcode
 */
Direction stringToDirection(const std::string &direction);

#endif //HIQ_PROGRAMMING_DIRECTION_H
