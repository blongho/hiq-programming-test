#ifndef HIQ_PROGRAMMING_TESTCASEREADER_H
#define HIQ_PROGRAMMING_TESTCASEREADER_H

#include <string>
#include <vector>
#include "TestCase.h"
#include "Robot.h"

/**
 * \class TestCaseReader
 * @brief Utility class to read tests cases from a file
 */
class TestCaseReader {
public:
    /**
     * @brief Get the tests cases that have been read from file
     * @return  a vector of TestCase's
     */
    [[nodiscard]] std::vector<TestCase> getTestCases() const;

    /**
     * @brief The default constructor.
     */
    TestCaseReader() = default;

    /**
     * Read the contents of the tests file;
     */
    void readCommand();

private:
    std::vector<TestCase> testCases; //!< Container to hold the cases read from file

#ifdef TEST_SAMPLES_FILE
    const std::string test_file = TEST_SAMPLES_FILE;
#else
    const std::string test_file{"../test_cases.txt"};
#endif

    /**
     * Extract the contents of a robot from a string starting with PLACE
     * @param line the line to parse
     * @return a newly created Robot from the line
     */
    static Robot extractRobotStateFromPlaceString(const std::string &line);

    /**
     * @brief Check if a string read is one of the actions <br>
     * Valid actions are MOVE, LEFT, RIGHT, REPORT
     * @param basicString the string to check if it is a command or not
     * @return true if the string is a action, otherwise false
     *
     */
    static bool isAction(const std::string &basicString);

    /**
     * @brief Construct a Robot from a string starting with Output: x,y,direction
     * @param basicString the string Output: x,y,direction e,g Output: 1,2,EAST
     * @return a Robot constructed by parsing the string given as the parameter
     */
    static Robot extractRobotStateFromOutputString(const std::string &basicString);
};

#endif //HIQ_PROGRAMMING_TESTCASEREADER_H
