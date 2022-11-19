#ifndef HIQ_PROGRAMMING_TESTCASE_H
#define HIQ_PROGRAMMING_TESTCASE_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "Robot.h"

/**
 * \class TestCase
 * @brief Holds a tests case read
 * @details
 * A TestCase has the start state, the actions and the end (expected) state
 */
class TestCase {
public:
    /**
     * @brief Construct a Test case and initialize all its data members
     * @param startStart the initial state of the Robot
     * @param actions the different possible actions
     * @param endState the expected state of the Robot after executing the different actions
     */
    TestCase(const Robot &startStart, std::vector<Action> actions, const Robot &endState);

    /**
     * @brief The default constructor
     */
    TestCase() = default;

    /**
     * @brief Get the different actions to be executed
     * @return The different actions
     */
    [[nodiscard]] const std::vector<Action> &getActions() const;

    /**
     * Set the different actions for this tests case
     * @param actions the actions to be set
     */
    void setActions(const std::vector<Action> &actions);

    /**
     * @brief Get the start state for the tests case
     * @return the Robot's state at the beginning of the tests case
     */
    [[nodiscard]] const Robot &getStartStart() const;

    /**
     * @brief Set the start state of the Robot before the different actions
     * @param startStart the start state of the Robot before actions
     */
    void setStartStart(const Robot &startStart);

    /**
     * @brief Get the end state of the Robot after actions has been performed
     * @return the state of the Robot after the tests actions has been performed
     */
    [[nodiscard]] const Robot &getEndState() const;

    /**
     * @brief Set the end state of the robot
     * @param endState the expected state of the Robot after the tests actions has been performed
     */
    void setEndState(const Robot &endState);

private:
    Robot startStart{}; //!< The start state of the Robot before performing actions
    std::vector<Action> actions; //!< The different Action's to be performed on the Robot
    Robot endState{}; //!< The expected state of the robot after the tests has been executed
};


#endif //HIQ_PROGRAMMING_TESTCASE_H
