//
// Created by Longho Bernard Che on 2022-11-10.
//

#ifndef HIQ_PROGRAMMING_POINT_H
#define HIQ_PROGRAMMING_POINT_H

#include <iostream>

struct Point {

    Point(uint16_t p_x, uint16_t p_y) :
            x{p_x}, y{p_y} {}

    Point() = default;

    uint16_t x{};
    uint16_t y{};

};

std::ostream &operator<<(std::ostream &os, const Point &point);

std::istream &operator>>(std::istream &is, Point &point);

#endif //HIQ_PROGRAMMING_POINT_H
