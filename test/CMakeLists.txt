cmake_minimum_required(VERSION 3.0)

project(hiq_programming_test)

SET(CMAKE_CXX_STANDARD 17)

SET(TEST_SAMPLES_FILE "${CMAKE_SOURCE_DIR}/samples.txt" CACHE STRING "Path to file containing test cases")

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
        ../src/Robot.cpp
        ../src/TestCase.cpp
        ../src/TestCaseReader.cpp
        )

set(TEST_FILES
        test_point.cpp
        test_board.cpp
        test_robot.cpp)

if (TEST_SAMPLES_FILE)
    message("Test file path set to ${TEST_SAMPLES_FILE}")
else ()
    message("Test file path not set. Defaulting to ${TEST_SAMPLES_FILE}")
endif ()


add_executable(test ${SRC} ${TEST_FILES})

TARGET_LINK_LIBRARIES(test PRIVATE Catch2::Catch2WithMain)


