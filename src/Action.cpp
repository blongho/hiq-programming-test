#include "Action.h"
#include <algorithm>

Action actionFromString(std::string &action) {
    std::transform(action.begin(), action.end(), action.begin(), toupper);
    if (action == "MOVE") {
        return Action::MOVE;
    } else if (action == "LEFT") {
        return Action::LEFT;
    } else if (action == "RIGHT") {
        return Action::RIGHT;
    } else if (action == "REPORT") {
        return Action::REPORT;
    }  else {
        return Action::NONE;
    }
}