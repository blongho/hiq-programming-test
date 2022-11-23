/**
 * @file DemoApp.h
 * @brief Contains a demo for the demonstration of the system
 */
#ifndef HIQ_PROGRAMMING_DEMOAPP_H
#define HIQ_PROGRAMMING_DEMOAPP_H

#include "Robot.h"

/**
 * @class DemoApp
 * @brief Utility class for demonstrating the robotic motion
 */
class DemoApp {
public:
    /**
     * @brief The contructor
     */
    DemoApp();

    /**
     * @brief Run the demo app
     */
    void run();

private:
    /**
     * @brief The robot for the application
     */
    Robot robot;

    /**
     * @brief Indicates if the application should stop executing
     */
    bool stop{false};

    /**
     * @brief Calls the Robot#move() function
     */
    void move();

    /**
     * @brief Calls the Robot#left() function
     */
    void left();

    /**
     * @brief Calls the Robot#right() function
     */
    void right();

    /**
     * @brief Calls the Robot#report() function
     */
    void report();

    /**
     * @brief Displays the application interactive menu
     */
    void displayMenu();

    /**
     * Get the choice of the user
     * @return lower case char l,r,m,d,q
     */
    char getInput();
};


#endif //HIQ_PROGRAMMING_DEMOAPP_H
