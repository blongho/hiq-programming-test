#include <iomanip>

#include "Board.h"


Board::Board() {
    reset();
}

void Board::show(std::ostream &os) const {
    std::cout << std::string(25, '-') << "\n";
    for (const auto &row: boardCells) {
        for (const auto &col: row) {
            os << '[' << std::setw(3) << col << ']';
        }
        os << '\n';
    }
    std::cout << std::string(25, '-') << "\n";
}

void Board::update(const Point &point, const std::string &c) {
    reset();
    if (point.isValid()) {
        boardCells[transformValue(point.y)][point.x] = c;
    }
    show();
}

void Board::reset() {
    for (auto &i: boardCells) {
        for (auto &j: i) {
            j = " ";
        }
    }
}


constexpr uint16_t Board::transformValue(const uint16_t &val) {
    if (val == 4) return 0;
    if (val == 3) return 1;
    if (val == 2) return 2;
    if (val == 1) return 3;
    if (val == 0) return 4;
    return val;
}



