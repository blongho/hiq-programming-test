#ifndef HIQ_PROGRAMMING_POINT_H
#define HIQ_PROGRAMMING_POINT_H

#include <iostream>

struct Point {
    /**
     * A point's parameterized constructor
     * @param p_x the x value (signed int)
     * @param p_y the y value (signed int)
     */
    Point(int p_x, int p_y);

    /**
     * Default constructor of a Point object
     */
    Point() = default;

    /**
     * The overloaded equality operator used to compare if two points are equal
     * @param other the other point to compare
     * @return true if both @param other and this current point are equal
     */
    bool operator==(const Point &other) const;

    /**
     * Checks the validity of a Point. A point is valid if the 0<=x<=4 and 0<=y<=4
     * @return true if the x and y values are within the range [0,4]
     */
    [[nodiscard]] bool isValid() const;

    /*!
     * @brief An overloaded ostream operator for printing out a Point
     *
     * @param os the ostream (std::ostream&)
     * @param point The point
     * @return std::ostream& the ostream
     */
    friend std::ostream &operator<<(std::ostream &os, const Point &point);

    int x{}; /*< The x value of a point */
    int y{}; /*< The y value of a point */
};

#endif //HIQ_PROGRAMMING_POINT_H
