cmake_minimum_required(VERSION 3.0)

project(hiq_programming_test)

SET(CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE RELEASE)
include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.1.1
)

FetchContent_MakeAvailable(Catch2)

MACRO(add_test_file name src)
    ADD_EXECUTABLE(${name} ${src} ${name}.cpp)
    TARGET_LINK_LIBRARIES(${name} PRIVATE Catch2::Catch2WithMain)
ENDMACRO()
set(SRC_FILES
        ../src/Direction.cpp
        ../src/Board.cpp
        ../src/Point.cpp
        ../src/Robot.cpp )

add_test_file(test_board ../src/Board.cpp)
add_test_file(test_point ../src/Point.cpp)

add_executable(robot_test ${SRC_FILES} test_robot.cpp)
TARGET_LINK_LIBRARIES(robot_test PRIVATE Catch2::Catch2WithMain)



