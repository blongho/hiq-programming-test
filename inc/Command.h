//
// Created by Longho Bernard Che on 2022-11-13.
//

#ifndef HIQ_PROGRAMMING_COMMAND_H
#define HIQ_PROGRAMMING_COMMAND_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using Action = std::string;

struct StartCommand {
    std::string place{};
    uint16_t x{};
    uint16_t y{};
    std::string direction{};

    inline bool isValidPlacement() const { return x <= 4 && x >= 0 && y <= 4 && x >= 0; };

    friend std::ostream &operator<<(std::ostream &os, const StartCommand &start);

    friend std::istream &operator>>(std::istream &is, StartCommand &start);

};

class Command {
public:
    Command(const StartCommand &start, const std::vector<Action> &actions);

    Command() = default;

    [[nodiscard]] const StartCommand &getStart() const;

    void setStart(const StartCommand &start);

    [[nodiscard]] const std::vector<Action> &getActions() const;

    void setActions(const std::vector<Action> &actions);

    friend std::ostream &operator<<(std::ostream &os, const Command &command);

    friend std::istream &operator>>(std::istream &is, Command &command);

    void readOn(std::ifstream &);

private:
    StartCommand start;
    std::vector<Action> actions;


};


#endif //HIQ_PROGRAMMING_COMMAND_H
