cmake_minimum_required(VERSION 3.0)

project(hiq_programming_test)

SET(CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE RELEASE)

SET(TEST_SAMPLES_FILE "${CMAKE_SOURCE_DIR}/samples.txt" CACHE STRING "Path to file containing test cases")

message("Test samples is set to ${TEST_SAMPLES_FILE}")
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
        ../src/Robot.cpp
        ../src/TestCommandReader.cpp)

add_test_file(test_board ../src/Board.cpp)
add_test_file(test_point ../src/Point.cpp)

if(TEST_FILE_PATH)
    message(INFO "Test file path set to ${TEST_FILE_PATH}")
else()
    message(INFO "Test file path not set. Defaulting to ${CMAKE_SOURCE_DIR}/tests.txt")
endif()

add_executable(test_robot ${SRC_FILES} test_robot.cpp)
TARGET_LINK_LIBRARIES(test_robot PRIVATE Catch2::Catch2WithMain)


