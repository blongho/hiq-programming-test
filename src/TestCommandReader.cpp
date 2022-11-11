//
// Created by Longho Bernard Che on 2022-11-11.
//

#include "TestCommandReader.h"
#include <fstream>
#include <iostream>

void TestCommandReader::readCommand() {
    std::ifstream ifs(test_file);
    if (!ifs) {
        std::cerr << "Could not read the test file\n";
        exit(1);
    } else {
        std::string line{};
        while (std::getline(ifs, line)) {
            std::cout << "Read the line " << line << std::endl;
        }
    }

}
