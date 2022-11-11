//
// Created by Longho Bernard Che on 2022-11-10.
//
#include <iomanip>

#include "Board.h"


Board::Board() {
    reset();
}

void Board::show(std::ostream &os) const {
    std::cout << std::string(15, '-') << "\n";

    for (const auto & row : location) {
        for (const auto & col : row) {
            os << '[' << std::setw(3) <<  col << ']';
        }
        os << '\n';
    }
    std::cout << std::string(15, '-') << "\n";
}

void Board::insert(const Point &point, const std::string &c) {
    reset();
    location[(transformX(point.x))][point.y] = c;
}

void Board::reset() {
    for (auto & i : location) {
        for (auto & j : i) {
            j = " ";
        }
    }
}


constexpr uint16_t Board::transformX(const uint16_t &val) {
    if (val == 4) return 0;
    if (val == 3) return 1;
    if (val == 2) return 2;
    if (val == 1) return 3;
    if (val == 0) return 4;
    return val;
}



