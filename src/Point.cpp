#include "Point.h"


Point::Point(int p_x, int p_y) :
        x{p_x}, y{p_y} {}

std::ostream &operator<<(std::ostream &os, const Point &point) {
    os << point.x << "," << point.y;
    return os;
}


bool Point::operator==(const Point &other) const {
    return x == other.x && y == other.y;
}

bool Point::isValid() const {
    return x >= 0 && x <= 4 && y >= 0 && y <= 4;
}
