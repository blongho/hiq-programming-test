//
// Created by Longho Bernard Che on 2022-11-13.
//

#include "Command.h"
#include <sstream>

Command::Command(const StartCommand &start, const std::vector<Action> &actions) : start(start), actions(actions) {}

const StartCommand &Command::getStart() const {
    return start;
}

void Command::setStart(const StartCommand &p_start) {
    Command::start = p_start;
}

const std::vector<Action> &Command::getActions() const {
    return actions;
}

void Command::setActions(const std::vector<Action> &p_actions) {
    Command::actions = p_actions;
}

std::ostream &operator<<(std::ostream &os, const Command &command) {
    StartCommand start;
    os << start << "\n";
    for (const auto &action: command.getActions()) {
        os << action << "\n";
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const StartCommand &start) {
    os << start.place << "," << start.x << "," << start.y << "," << start.direction;
    return os;
}


std::istream &operator>>(std::istream &is, Command &command) {
    StartCommand start;
    is >> start;
    std::vector<Action> actions;
    std::string action;

    while (std::getline(is, action)) {
        //std::cout << action << std::endl;
        if (!action.empty()) {
            actions.push_back(action);
        }else{
            std::cout << action << std::endl;
        }
    }

    command.setActions(actions);
    command.setStart(start);
    /*is >> start;
    std::vector<Action> actions;
    std::string action;
    command.setActions(actions);
    command.setStart(start);*/

    return is;
}

void Command::readOn(std::ifstream &ifs) {
    StartCommand startCommand;
}

std::istream &operator>>(std::istream &is, StartCommand &start) {
    std::string place{}, direction{}, tmpX{}, tmpY{};
    std::getline(is, place, ' ');
    std::getline(is, tmpX, ',');
    std::getline(is, tmpY, ',');
    std::getline(is, direction, '\n');
    start.place = place;
    try {
        start.x = std::stoi(tmpX);
        start.y = std::stoi(tmpY);
    } catch (const std::exception &exception) {
        std::cout << exception.what() << std::endl;
    }
    start.direction = direction;

    return is;
}