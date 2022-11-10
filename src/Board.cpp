//
// Created by Longho Bernard Che on 2022-11-10.
//
#include <iomanip>

#include "Board.h"


Board::Board() {
    reset();
}

void Board::show(std::ostream &os) const {
    for (const auto & row : location) {
        for (const auto & col : row) {
            os << '[' << col << ']';
        }
        os << '\n';
    }
}

bool Board::isEdge(uint16_t x, uint16_t y) const {
    return location[x][y].empty();
}

void Board::insert(const Point &point, char c) {
    reset();
    location[(transformX(point.x))][point.y] = c;
    show();
}

void Board::reset() {
    for (auto & i : location) {
        for (auto & j : i) {
            j = " ";
        }
    }
}

void Board::transpose() {
    for (uint16_t i = 0; i < ROWS; ++i) {
        for (uint16_t j = 0; j < COLUMNS; ++j) {
            location[i][j] = location[(i - 5 % 5)][j];
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



