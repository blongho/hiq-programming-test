#include <iomanip>
#include <algorithm>
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
    std::fill(&boardCells[0][0], (&boardCells[0][0] + sizeof(boardCells) / sizeof(boardCells[0][0])), " ");
}


constexpr int Board::transformValue(const int &val) {
    if (val == 4) return 0;
    if (val == 3) return 1;
    if (val == 2) return 2;
    if (val == 1) return 3;
    if (val == 0) return 4;
    return val;
}