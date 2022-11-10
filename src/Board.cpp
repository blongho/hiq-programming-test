//
// Created by Longho Bernard Che on 2022-11-10.
//
#include <iomanip>

#include "Board.h"


Board::Board() {
    reset();
       transpose();
    show();
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
    return true;
}

void Board::insert(const Point &point, char c) {
    location[(transformX(point.x))][point.y] = c;
    show();
}

void Board::reset() {
    for (ushort i = 0; i < ROWS; ++i) {
        for (ushort j = 0; j < COLUMNS; ++j) {
            location[i][j] = std::to_string(i)+" " + std::to_string(j);
        }
    }
}

void Board::transpose() {
    for (ushort i = 0; i < ROWS; ++i) {
        for (ushort j = 0; j < COLUMNS; ++j) {
            location[i][j] = location[(i-5%5)][j];
        }
    }
}


const int Board::transformX(const ushort &val) const{
    if(val == 4) return 0;
    if(val == 3) return 1;
    if(val == 2) return 2;
    if(val == 1) return 3;
    if(val == 0) return 4;
    return val;
}



