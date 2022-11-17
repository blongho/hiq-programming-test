//
// Created by Longho Bernard Che on 2022-11-10.
//

#include "CommandReader.h"
#include "Robot.h"


int main() {
    /*CommandReader commandReader;
    commandReader.readCommand();*/
    Robot robot({0, 0}, Direction::NORTH);
    robot.move();
    robot.right();
    robot.move();
    robot.move();
    robot.report();
    return 0;
}


