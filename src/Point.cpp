#include "Point.h"

std::ostream &operator<<(std::ostream &os, const Point &point) {
    os << point.x << "," << point.y;
    return os;
}

std::istream &operator>>(std::istream &is, Point &point) {
    char c{','};
    is >> point.x >> c >> point.y;
    return is;
}
