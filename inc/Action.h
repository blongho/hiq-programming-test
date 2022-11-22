/**
 * @file Action.h
 * @brief Holds the different actions that a robot can take
 * @author Longho Bernard Che
 */
#ifndef HIQ_PROGRAMMING_ACTION_H
#define HIQ_PROGRAMMING_ACTION_H

#include <string>
#include <iostream>

/**
 * @brief The actions that a robot can take
 * \enum Action
 */
enum class Action {
    MOVE, //!< Informs the Robot to move the robot one step to the direction that it is facing
    LEFT, //!< Informs the Robot 90 degrees left
    RIGHT, //!< Informs the Robot to turn 90 degrees right
    REPORT, //!< Informs the Robot to report its current state
    NONE //!< The robot does nothing
};

/**
 * Get the action from a string
 * @param action the Action as a string
 * @return The corresponding action
 */
Action actionFromString(const std::string &action);

std::ostream &operator<<(std::ostream&, const Action &);

#endif //HIQ_PROGRAMMING_ACTION_H
