#include "TestCase.h"
#include <sstream>
#include <utility>
#include <sstream>

TestCase::TestCase(const Robot &startStart, std::vector<Action> actions, const Robot &endState) : startState(
        startStart), actions(std::move(actions)), endState(endState) {}

const std::vector<Action> &TestCase::getActions() const {
    return actions;
}

void TestCase::setActions(const std::vector<Action> &p_actions) {
    TestCase::actions = p_actions;
}

const Robot &TestCase::getStartState() const {
    return startState;
}

void TestCase::setStartState(const Robot &startStart) {
    TestCase::startState = startStart;
}

const Robot &TestCase::getEndState() const {
    return endState;
}

void TestCase::setEndState(const Robot &p_endState) {
    TestCase::endState = p_endState;
}







