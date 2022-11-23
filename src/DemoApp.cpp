#include "DemoApp.h"

DemoApp::DemoApp()
        : robot{Robot(Point(0, 0), Direction::EAST)} {
}

void DemoApp::report() {
    robot.report();
}

void DemoApp::move() {
    std::cout << "Making a move ...\n";
    robot.move();
}

void DemoApp::left() {
    std::cout << "Making a left turn ...\n";
    robot.left();
}

void DemoApp::right() {
     std::cout << "Making a right turn ...\n";
    robot.right();
}

void DemoApp::run()  {
    displayMenu();
}

void DemoApp::displayMenu() {
    std::cout  << "\nRobot state\n";
    robot.report();
    std::cout  << "\n";
    while (!stop) {
        std::cout  << "\n" << std::string(20, '-') << "\n"
           << "ROBOT MENU\n"
           << "1 - Move\n"
           << "2 - Left\n"
           << "3 - Right\n"
           << "4 - Report\n"
           << "0 - Exit\n"
           << std::string(20, '-') << "\n\n"
           << "Your choice: ";

        int choice{-1};

        std::cin >> choice;

        switch (choice) {
            case 1:
                move();
                break;
            case 2:
                left();
                break;
            case 3:
                right();
                break;
            case 4:
                report();
                break;
            case 0:
                std::cout << "Exiting the program ...\n";
                stop = true;
                break;
            default:
                std::cout << "\nInvalid Choice. Choose between [0-4]\n";
                break;
        }
    }
}


