#ifndef HIQ_PROGRAMMING_POINT_H
#define HIQ_PROGRAMMING_POINT_H

#include <iostream>

struct Point {
    /**
     * A point's parametarized constructor
     * @param p_x the x value (unsigned short)
     * @param p_y the y value (unsigned short)
     */
    Point(uint16_t p_x, uint16_t p_y);

    /**
     * Default constructor of a Point object
     */
    Point() = default;

    /**
     * The overloaded equality operator used to compare if two points are equal
     * @param other
     * @return
     */
    bool operator==(const Point &other) const;

    /**
     * The overloaded addition operator used to add two points
     * @param other the other point to be added
     * @return a new Point whose sum is equal to the current and the other one given
     */
    Point operator+(const Point &other) const;

    Point operator-(const Point &other) const;

    /**
     * Subtract n units from the y value
     * @param y_val the value to be subtracted from this point's y value
     * @return a new point value with the y value minus the value given in this function
     */
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
