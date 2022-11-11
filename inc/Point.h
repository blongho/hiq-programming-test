#ifndef HIQ_PROGRAMMING_POINT_H
#define HIQ_PROGRAMMING_POINT_H

#include <iostream>

struct Point {

    Point(uint16_t p_x, uint16_t p_y) :
            x{p_x}, y{p_y} {}

    Point() = default;

    bool operator==(const Point &other) const;

    Point operator+(const Point &other) const;

    Point operator-(const Point &other) const;

    [[nodiscard]] Point minusY(const uint16_t &y_val) const;

    [[nodiscard]] Point minusX(const uint16_t &x_val) const;

    [[nodiscard]] Point plusX(const uint16_t &y_val) const;

    [[nodiscard]] Point plusY(const uint16_t &x_val) const;

    uint16_t x{};
    uint16_t y{};


};

std::ostream &operator<<(std::ostream &os, const Point &point);

std::istream &operator>>(std::istream &is, Point &point);

#endif //HIQ_PROGRAMMING_POINT_H
