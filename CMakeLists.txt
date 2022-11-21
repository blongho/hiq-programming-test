cmake_minimum_required(VERSION 3.0)

project(hiq_programming)

set(CMAKE_CXX_STANDARD 17)


include_directories(inc)

set(SRC_FILES
        src/Point.cpp
        src/Direction.cpp
        src/Action.cpp
        src/Board.cpp
        src/Robot.cpp
        src/TestCase.cpp
        src/TestCaseReader.cpp
        )

add_executable(app ${SRC_FILES} Main.cpp)

# Enable testing for the project
enable_testing()

add_subdirectory(tests)