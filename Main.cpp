
#include "CommandReader.h"
#include "Robot.h"


int main() {
    CommandReader commandReader;
    commandReader.readCommand();
    const auto testCases = commandReader.getTestCases();
    for (const auto &item: testCases){
        std::cout << "\n\nStart state --> " << item.getStartStart() << std::endl;
        std::cout << "Actions --> ";
        for (const auto &action: item.getActions()){
            std::cout << action << ",";
        }
        std::cout << std::endl;
        std::cout << "End state --> " << item.getEndState() << std::endl;
    }
   Robot robot({0, 4}, Direction::NORTH);
    robot.move();
    robot.right();
    robot.move();
    robot.move();
    robot.report();
    std::cin.get();
    return 0;
}


