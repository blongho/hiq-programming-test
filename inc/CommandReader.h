//
// Created by Longho Bernard Che on 2022-11-11.
//

#ifndef HIQ_PROGRAMMING_COMMANDREADER_H
#define HIQ_PROGRAMMING_COMMANDREADER_H

#include <string>
#include <vector>
#include "Command.h"

class CommandReader {
public:
    void readCommand();


private:
    std::vector<Command> commands;

#ifdef TEST_SAMPLES_FILE
    const std::strign test_file = TEST_SAMPLES_FILE;
#else
    const std::string test_file{"../sample_data.txt"};
#endif

};


#endif //HIQ_PROGRAMMING_COMMANDREADER_H
