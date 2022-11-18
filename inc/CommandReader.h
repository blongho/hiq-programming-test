//
// Created by Longho Bernard Che on 2022-11-11.
//

#ifndef HIQ_PROGRAMMING_COMMANDREADER_H
#define HIQ_PROGRAMMING_COMMANDREADER_H

#include <string>
#include <vector>
#include "TestCase.h"
#include "Robot.h"

class CommandReader {
public:
    void readCommand();


private:
    std::vector<TestCase> testCases;
public:
    const std::vector<TestCase> &getTestCases() const;

private:

#ifdef TEST_SAMPLES_FILE
    const std::strign test_file = TEST_SAMPLES_FILE;
#else
    const std::string test_file{"../sample_data.txt"};
#endif

    static Robot extractRobotStateFromPlaceString(const std::string &line) ;

    static bool isCommand(const std::string& basicString);

    static Robot extractRobotStateFromOutputString(const std::string& basicString);
};


#endif //HIQ_PROGRAMMING_COMMANDREADER_H
