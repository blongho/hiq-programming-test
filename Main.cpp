//
// Created by Longho Bernard Che on 2022-11-10.
//

#include "CommandReader.h"
#include "Robot.h"


int main() {
    Direction direction;
    std::cout << "Direction is " <<  directionToString(direction) << std::endl;
    CommandReader commandReader;
    commandReader.readCommand();
    for (const auto &item: commandReader.getTestCases()){
        std::cout << "\n\nStart state --> " << item.getStartStart() << std::endl;
        std::cout << "Actions --> ";
        for (const auto &action: item.getActions()){
            std::cout << action << ",";
        }
        std::cout << std::endl;
        std::cout << "End state --> " << item.getEndState() << std::endl;
    }
   /* Robot robot({0, 0}, Direction::NORTH);
    robot.move();
    robot.right();
    robot.move();
    robot.move();
    robot.report();*/
    return 0;
}


