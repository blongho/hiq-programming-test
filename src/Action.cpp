#include "Action.h"

Action actionFromString(const std::string &action) {
    if (action == "MOVE") {
        return Action::MOVE;
    } else if (action == "LEFT") {
        return Action::LEFT;
    } else if (action == "RIGHT") {
        return Action::RIGHT;
    } else if (action == "REPORT") {
        return Action::REPORT;
    } else {
        return Action::NONE;
    }
}

std::ostream &operator<<(std::ostream&os, const Action &action){
    switch (action) {
        case Action::MOVE:
            os << "MOVE";
            break;
        case Action::LEFT:
            os << "LEFT";
            break;
        case Action::RIGHT:
            os << "RIGHT";
            break;
        case Action::REPORT:
            os << "REPORT";
            break;
        case Action::NONE:
            os << "NONE";
            break;
    }
    return os;
}