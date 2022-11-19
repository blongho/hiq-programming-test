cmake_minimum_required(VERSION 3.0)

project(hiq_programming)

set(CMAKE_CXX_STANDARD 17)


include_directories(inc)

set(SRC_FILES
        src/Board.cpp
        src/Point.cpp
        src/Direction.cpp
        src/Robot.cpp
        src/TestCase.cpp
        src/TestCaseReader.cpp
        )

add_executable(app ${SRC_FILES} Main.cpp)

add_subdirectory(test)