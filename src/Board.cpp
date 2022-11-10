//
// Created by Longho Bernard Che on 2022-11-10.
//
#include <iomanip>

#include "Board.h"


Board::Board() {
    reset();
}

void Board::show(std::ostream &os) const {
    os << '\n';
    os << std::setw(2) << ' ';
    for (int col = 0; col < COLUMNS; ++col) {
        os << std::right << std::setw(6) << col;
    }
    os << '\n';

    for (int row = 0; row < ROWS; ++row) {
        os << std::left << std::setw(3) << row; // print the row numbers
        for (int col = 0; col < COLUMNS; col++) {
            os << '[' << std::setw(4) << location[row][col] << ']';
        }
        os << '\n';
    }
}

bool Board::isEdge() const {
    return location[0][0] ||
           location[0][1] ||
           location[0][2] ||
           location[0][3] ||
           location[0][4];
}

void Board::insert(const Point &point, char c) {
    location[(point.x + 4) % COLUMNS][point.y] = c;
}

void Board::reset() {
    for (auto &row: location) {
        for (char &col: row) {
            col = ' ';
        }
    }
}

void Board::transpose() {
    for (ushort i = 0; i < ROWS; ++i) {
        for (ushort j = 0; j < COLUMNS; ++j) {
            location[i][j] = location[j][i];
        }
    }
}




