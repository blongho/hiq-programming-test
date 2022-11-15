cmake_minimum_required(VERSION 3.0)

project(hiq_programming)

set(CMAKE_CXX_STANDARD 20)


include_directories(inc)

set(SRC_FILES
        src/Board.cpp
        src/Point.cpp
        src/Direction.cpp
        src/Robot.cpp
        src/Command.cpp
        src/CommandReader.cpp
        )

add_executable(app ${SRC_FILES} Main.cpp)

add_subdirectory(test)