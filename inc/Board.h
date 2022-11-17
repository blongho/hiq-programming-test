#ifndef HIQ_PROGRAMMING_BOARD_H
#define HIQ_PROGRAMMING_BOARD_H

#include <iostream>
#include <array>
#include "Point.h"
#include <string>

class Board {
public:
    Board();

    void show(std::ostream &os = std::cout) const;

    void reset();

    void insert(const Point &, const std::string &);

private:
    static constexpr uint16_t ROWS{5};
    static constexpr uint16_t COLUMNS{5};
    std::string location[ROWS][COLUMNS]{};

    static constexpr uint16_t transformValue(const uint16_t &val) ;

};


#endif //HIQ_PROGRAMMING_BOARD_H
