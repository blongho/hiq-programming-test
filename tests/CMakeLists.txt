cmake_minimum_required(VERSION 3.0)

project(hiq_programming_test)

SET(CMAKE_CXX_STANDARD 17)


set(TEST_NAME test_app)

Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.0.1
)

FetchContent_MakeAvailable(Catch2)

set(SRC
        ../src/Action.cpp
        ../src/Point.cpp
        ../src/Direction.cpp
        ../src/Board.cpp
        ../src/Robot.cpp
        ../src/TestCase.cpp
        ../src/TestCaseReader.cpp
        )

MESSAGE(STATUS "Current directory is ${CMAKE_CURRENT_BINARY_DIR}")
if (TEST_SAMPLES_FILE)
    set(TEST_CASE_FILE "${CMAKE_SOURCE_DIR}/${TEST_SAMPLES_FILE}" CACHE STRING "Path to file containing test cases")
    add_definitions(-DTEST_SAMPLES_FILE="${TEST_CASE_FILE}")
    message(STATUS "Test file path set to ${TEST_CASE_FILE}")
else ()
    set(TEST_SAMPLES_FILE "${CMAKE_SOURCE_DIR}/test_cases.txt" CACHE STRING "Path to file containing test cases")
    add_definitions(-DTEST_SAMPLES_FILE="${TEST_SAMPLES_FILE}")
    message(STATUS "Test file path not set. Defaulting to ${TEST_SAMPLES_FILE}")
endif ()

set(POINT_TEST_SRC ../src/Point.cpp test_point.cpp test_direction.cpp)


set(ROBOT_TEST_SRC
        ${SRC}
        test_robot.cpp)

set(ACTION_TEST_SRC ../src/Action.cpp test_action.cpp)


set(TEST_CASE_SRC ../src/TestCase.cpp test_testcase.cpp)


add_executable(test_point ${POINT_TEST_SRC})
target_link_libraries(test_point PRIVATE Catch2::Catch2WithMain)

add_executable(test_robot ${ROBOT_TEST_SRC})
target_link_libraries(test_robot PRIVATE Catch2::Catch2WithMain)

add_executable(test_action ${ACTION_TEST_SRC})
target_link_libraries(test_action PRIVATE Catch2::Catch2WithMain)

add_executable(test_testcase ${ACTION_TEST_SRC})
target_link_libraries(test_testcase PRIVATE Catch2::Catch2WithMain)

add_executable(test_testcase_reader ${SRC} test_testcase_reader.cpp)
target_link_libraries(test_testcase_reader PRIVATE Catch2::Catch2WithMain)

add_executable(test_direction ../src/Direction.cpp test_direction.cpp)
target_link_libraries(test_direction PRIVATE Catch2::Catch2WithMain)


add_test(test_point test_point)
add_test(test_action test_action)
add_test(test_direction test_direction)
add_test(test_testcase test_testcase)
add_test(test_testcase_reader test_testcase_reader)
add_test(test_robot test_robot)