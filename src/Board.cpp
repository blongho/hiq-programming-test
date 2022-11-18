#include <iomanip>

#include "Board.h"


Board::Board() {
    reset();
}

void Board::show(std::ostream &os) const {
    std::cout << std::string(25, '-') << "\n";
    for (const auto & row : location) {
        for (const auto & col : row) {
            os << '[' << std::setw(3) <<  col << ']';
        }
        os << '\n';
    }
    std::cout << std::string(25, '-') << "\n";
}

void Board::insert(const Point &point, const std::string &c) {
    reset();
    location[transformValue(point.y)][point.x] = c;
}

void Board::reset() {
    for (auto & i : location) {
        for (auto & j : i) {
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



