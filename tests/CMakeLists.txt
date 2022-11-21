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

if (TEST_SAMPLES_FILE)
    set(TEST_CASE_FILE "${CMAKE_SOURCE_DIR}/${TEST_SAMPLES_FILE}" CACHE STRING "Path to file containing test cases")
    add_definitions(-DTEST_SAMPLES_FILE="${TEST_CASE_FILE}")
    message(STATUS "Test file path set to ${TEST_CASE_FILE}")
else ()
    set(TEST_SAMPLES_FILE "${CMAKE_SOURCE_DIR}/test_cases.txt" CACHE STRING "Path to file containing test cases")
    add_definitions(-DTEST_SAMPLES_FILE="${TEST_SAMPLES_FILE}")
    message(STATUS "Test file path not set. Defaulting to ${TEST_SAMPLES_FILE}")
endif ()

macro(make_executable exec_name exec_sources)
    add_executable(${exec_name} ${exec_sources})
    target_link_libraries(${exec_name} PRIVATE Catch2::Catch2WithMain)
endmacro()

set(POINT_TEST_SRC ../src/Point.cpp test_point.cpp)


set(ROBOT_TEST_SRC
        ${SRC}
        test_robot.cpp)

set(BOARD_TEST_SRC ../src/Point.cpp ../src/Board.cpp)

set(ACTION_TEST_SRC ../src/Action.cpp test_action.cpp)

set(APP_TEST_SRC ${SRC} test_action.cpp test_point.cpp test_board.cpp test_robot.cpp)
make_executable(test_point ${POINT_TEST_SRC})

make_executable(test_robot ${ROBOT_TEST_SRC})

make_executable(test_action ${ACTION_TEST_SRC})

make_executable(test_board ${BOARD_TEST_SRC})

make_executable(test_app ${APP_TEST_SRC})

#add_test(${TEST_NAME} ${TEST_NAME})
add_test(test_robot test_robot)
add_test(test_point test_point)
add_test(test_action test_action)
add_test(test_board test_board)
add_test(test_app test_app)
