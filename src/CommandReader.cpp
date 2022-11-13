//
// Created by Longho Bernard Che on 2022-11-11.
//

#include "CommandReader.h"
#include <fstream>
#include <iostream>
#include <string_view>
#include "Command.h"

void CommandReader::readCommand() {
    std::ifstream ifs(test_file);
    if (!ifs) {
        std::cerr << "Could not read the test file\n";
        exit(1);
    } else {
        std::string line{};
        Command command;
         ifs >> command;
         std::cout << command << std::endl;
         ifs >> command;
         std::cout << std::string(20, '*') << std::endl
                   << command << std::endl;
        /*while (ifs >> command) {
            std::cout << std::string(20, '=') << std::endl
                      << command
                      << std::string(20, '=')
                      << std::endl << std::endl;
        }*/
    }

}
