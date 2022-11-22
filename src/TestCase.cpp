#include "TestCase.h"
#include <sstream>
#include <utility>
#include <sstream>

TestCase::TestCase(const Robot &startStart, std::vector<Action> p_actions, const Robot &endState) : startState(
        startStart), actions(std::move(p_actions)), endState(endState) {}

std::vector<Action> TestCase::getActions() const {
    return actions;
}

void TestCase::setActions(const std::vector<Action> &p_actions) {
    TestCase::actions = p_actions;
}

Robot TestCase::getStartState() const {
    return startState;
}

void TestCase::setStartState(const Robot &startStart) {
    TestCase::startState = startStart;
}

Robot TestCase::getEndState() const {
    return endState;
}

void TestCase::setEndState(const Robot &p_endState) {
    TestCase::endState = p_endState;
}







