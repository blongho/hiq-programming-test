//
// Created by Longho Bernard Che on 2022-11-11.
//

#include "CommandReader.h"
#include <fstream>
#include <iostream>
#include <string_view>
#include "Command.h"

void CommandReader::readCommand()
{
    std::ifstream ifs(test_file);
    if (!ifs)
    {
        std::cerr << "Could not read the test file\n";
        exit(1);
    } else
    {
        StartCommand start;
        std::vector<std::string> commands;
        Command testCase;
        const auto digits{"0123456789"};
        std::string line{};
        while (std::getline(ifs, line))
        {
            if (!line.empty())
            {
                if (line.find("PLACE") !=std::string::npos)
                {
                    start.place = line.substr(0, line.find_first_of(' '));
                    const auto x_position = line.find_first_of(digits);
                    const auto y_string = line.substr(x_position + 2, line.rfind(','));
                   // std::cout << y_string << std::endl;
                    start.x = std::stoi(line.substr(x_position));
                    start.y = std::stoi(y_string);
                    start.direction = line.substr(line.rfind(',')+1);
                    std::cout << start << std::endl;
                }
            }

        }
        testCase.start = start;
        testCase.commands = commands;
    }

}
