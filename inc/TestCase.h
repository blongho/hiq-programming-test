//
// Created by Longho Bernard Che on 2022-11-13.
//

#ifndef HIQ_PROGRAMMING_TESTCASE_H
#define HIQ_PROGRAMMING_TESTCASE_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "Robot.h"

using Action = std::string;

class TestCase {
public:
    TestCase(const Robot &startStart, const std::vector<Action> &actions, const Robot &endState);

    TestCase() = default;

    [[nodiscard]] const std::vector<Action> &getActions() const;

    void setActions(const std::vector<Action> &actions);

    [[nodiscard]] const Robot &getStartStart() const;

    void setStartStart(const Robot &startStart);

    [[nodiscard]] const Robot &getEndState() const;

    void setEndState(const Robot &endState);

private:
    Robot startStart{};
    std::vector<Action> actions;
    Robot endState{};
};

#endif //HIQ_PROGRAMMING_TESTCASE_H
