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

bool Point::operator==(const Point &other) const {
    return x == other.x && y == other.y;
}

Point Point::operator+(const Point &other) const {
    const Point point(x + other.x, y + other.y);
    return point;
}

Point Point::operator-(const Point &other) const {
    const Point point(x - other.x, y - other.y);
    return point;
}

Point Point::minusY(const uint16_t &y_val) const {
    const Point tmp(x, y - y_val);
    return tmp;
}

Point Point::minusX(const uint16_t &x_val) const {
    const Point tmp(x - x_val, y);
    return tmp;
}

Point Point::plusX(const uint16_t &x_val) const {
    const Point tmp(x + x_val, y);
    return tmp;
}

Point Point::plusY(const uint16_t &y_val) const {
    const Point tmp(x, y + y_val);
    return tmp;
}
