#include "Action.h"

Action actionFromString(const std::string &action) {
    if (action == "MOVE") {
        return Action::MOVE;
    } else if (action == "LEFT") {
        return Action::LEFT;
    } else if (action == "RIGHT") {
        return Action::RIGHT;
    } else {
        return Action::REPORT;
    }
}