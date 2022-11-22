/**
 * @file Board.h
 * @brief Utility class to create a visual representation of the robot
 * @author Longho Bernard Che
 */
#ifndef HIQ_PROGRAMMING_BOARD_H
#define HIQ_PROGRAMMING_BOARD_H

#include <iostream>
#include <array>
#include "Point.h"
#include <string>

/**
 * \class Board
 * @brief Utility class to create a visual representation of the robot
 */
class Board {
public:
    /**
     * Default constructor of the board
     */
    Board();

    /**
     * @brief Update the board and show it
     * @param point The coordinates of the robot
     * @param character the character to display at the position specified
     */
    void update(const Point &point, const std::string &character);

    /**
     * Destructor
     */
    ~Board() = default;

private:
    static constexpr short ROWS{5}; //!< The number of rows
    static constexpr short COLUMNS{5}; //!< The number of columns
    std::string boardCells[ROWS][COLUMNS]{}; //!< The board cells

    /**
     * @brief Utility function to transform the values of y-coordinates.
     * @param val the value to be added
     * @return the new value that is transformed (4->0, 3->1, 2->2, 1->3, 0->4)
     */
    static constexpr short transformValue(const short &val);

    /**
     * @brief Print the state of the board to the standard output
     * @param os the ostream
     */
    void show(std::ostream &os = std::cout) const;

    /**
     * @brief Reset the board by clearing all the values on it
     */
    void reset();
};


#endif //HIQ_PROGRAMMING_BOARD_H
