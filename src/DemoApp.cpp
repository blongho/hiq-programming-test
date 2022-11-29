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

void DemoApp::run() {
    displayMenu();
}

[[maybe_unused]] void DemoApp::displayMenu() {
    std::cout << "\nRobot state\n";
    robot.report();
    std::cout << "\n";
    while (!stop) {
        std::cout << "\nROBOT MENU\n"
                  << std::string(20, '-') << "\n"
                  << "M|m - Move    - move one unit in the direction of the robot\n"
                  << "L|l - Left    - turn the robot 90 left\n"
                  << "R|r - Right   - turn the robot 90 right\n"
                  << "D|d - Display - show the table with the robot\n"
                  << "Q|q - Quit or Exit the demo\n"
                  << std::string(20, '-') << "\n\n";


        const char choice = getInput();

        switch (choice) {
            case 'm':
                move();
                break;
            case 'l':
                left();
                break;
            case 'r':
                right();
                break;
            case 'd':
                report();
                break;
            case 'q':
                std::cout << "Exiting the program ...\n";
                stop = true;
                break;
            default:
                std::cout << "\nInvalid Choice. Choose between [0-4]\n";
                break;
        }
    }
}


[[maybe_unused]] char DemoApp::getInput() {
    bool valid = false;
    const std::string expectedValues{"lrmdq"};
    char choice{'a'};
    while (!valid) {
        std::cout << "\nYour Choice: ";
        std::string tempstr;

        std::getline(std::cin, tempstr);
        if (tempstr.empty()) {
            std::cout << "Valid entries are [L,R,M,D,Q,l,r,m,d,q]\n";
        } else {
            choice = std::tolower(tempstr[0]);
            if (expectedValues.find(choice) != std::string::npos) {
                valid = true;
            } else {
                std::cerr << "Bad entry! Valid entries are [L,R,M,D,Q,l,r,m,d,q]\n";
            }
        }
    }
    return choice;
}

