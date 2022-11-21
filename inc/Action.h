/**
 * \file Action.h
 * @brief Holds the different actions that a robot can take
 */
#ifndef HIQ_PROGRAMMING_ACTION_H
#define HIQ_PROGRAMMING_ACTION_H

#include <string>

/**
 * @brief The actions that a robot can take
 * \enum Action
 */
enum class Action {
    MOVE, //!< Informs the Robot to move the robot one step to the direction that it is facing
    LEFT, //!< Informs the Robot 90 degrees left
    RIGHT, //!< Informs the Robot to turn 90 degrees right
    REPORT, //!< Informs the Robot to report its current state
};

/**
 * Get the action from a string
 * @param action the Action as a string
 * @return The corresponding action
 */
Action actionFromString(const std::string &action);


#endif //HIQ_PROGRAMMING_ACTION_H
