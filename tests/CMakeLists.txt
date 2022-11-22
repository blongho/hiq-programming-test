cmake_minimum_required(VERSION 3.0)

project(hiq_programming_test)

SET(CMAKE_CXX_STANDARD 17)


set(TEST_NAME test_app)

Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.2.0
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

get_filename_component(MY_RESULT_ABSOLUTE_PATH_VAR
        "${CMAKE_CURRENT_LIST_DIR}/${MY_RELATIVE_PATH_VAR}"
        ABSOLUTE)


MESSAGE(STATUS "Current directory is ${CMAKE_SOURCE_DIR}")

if (TEST_SAMPLES_FILE)
    add_definitions(-DTEST_SAMPLES_FILE="${CMAKE_SOURCE_DIR}/${TEST_SAMPLES_FILE}")
    message(STATUS "Test file path set to ${CMAKE_SOURCE_DIR}/${TEST_SAMPLES_FILE}")
else ()
    add_definitions(-DTEST_SAMPLES_FILE="${CMAKE_SOURCE_DIR}/test_cases.txt")
    message(STATUS "Test file path not set. Defaulting to ${CMAKE_SOURCE_DIR}/test_cases.txt")
endif ()


set(ROBOT_TEST_SRC
        ${SRC}
        test_robot.cpp)



set(TEST_CASE_SRC ../src/TestCase.cpp test_testcase.cpp)


add_executable(test_point ../src/Point.cpp test_point.cpp)
target_link_libraries(test_point PRIVATE Catch2::Catch2WithMain)

add_executable(test_robot ${ROBOT_TEST_SRC})
target_link_libraries(test_robot PRIVATE Catch2::Catch2WithMain)


add_executable(test_testcase ${TEST_CASE_SRC})
target_link_libraries(test_testcase PRIVATE Catch2::Catch2WithMain)

add_executable(test_testcase_reader ${SRC} test_testcase_reader.cpp)
target_link_libraries(test_testcase_reader PRIVATE Catch2::Catch2WithMain)

add_test(test_point test_point)
add_test(test_testcase test_testcase)
add_test(test_testcase_reader test_testcase_reader)
add_test(test_robot test_robot)