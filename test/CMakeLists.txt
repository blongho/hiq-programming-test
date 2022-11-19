cmake_minimum_required(VERSION 3.0)

project(hiq_programming_test)

SET(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.1.1
)

FetchContent_MakeAvailable(Catch2)

set(SRC
        ../src/Board.cpp
        ../src/Point.cpp
        ../src/Direction.cpp
        ../src/Action.cpp
        ../src/Robot.cpp
        ../src/TestCase.cpp
        ../src/TestCaseReader.cpp
        )

set(TEST_FILES
        test_point.cpp
        test_board.cpp
        test_robot.cpp
        )

if (TEST_SAMPLES_FILE)
    set(TEST_CASE_FILE "${CMAKE_SOURCE_DIR}/${TEST_SAMPLES_FILE}" CACHE STRING "Path to file containing test cases")
    add_definitions(-DTEST_SAMPLES_FILE="${TEST_CASE_FILE}")
    message(STATUS "Test file path set to ${TEST_CASE_FILE}")
else ()
    set(TEST_SAMPLES_FILE "${CMAKE_SOURCE_DIR}/test_cases.txt" CACHE STRING "Path to file containing test cases")
    add_definitions(-DTEST_SAMPLES_FILE="${TEST_SAMPLES_FILE}")
    message(STATUS "Test file path not set. Defaulting to ${TEST_SAMPLES_FILE}")
endif ()

add_executable(test ${SRC} ${TEST_FILES})

TARGET_LINK_LIBRARIES(test PRIVATE Catch2::Catch2WithMain)


