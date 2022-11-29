#include "Point.h"

Point::Point(int p_x, int p_y) :
        x{p_x}, y{p_y} {}

bool Point::operator==(const Point &other) const {
    return x == other.x && y == other.y;
}

bool Point::isValid() const {
    return x >= min() && x <= max() && y >= min() && y <= max();
}

int Point::max() {
    return 4;
}

int Point::min() {
    return 0;
}
