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
     * The overloaded addition operator used to add two points
     * @param other the other point to be added
     * @return a new Point whose sum is equal to the current and the other one given
     */
    Point operator+(const Point &other) const;

    /*!
     * @brief Subtract a @param other Point from the current point
     *
     * @param other the other opint whose x,y values shall be subtracted from the current point
     * @return Point the updated point
     */
    Point operator-(const Point &other) const;

    /**
     * Subtract n units from the y value
     * @param y_units the value to be subtracted from this point's y value
     * @return a new point value with the y value minus the value given in this function
     */
    [[nodiscard]] Point minusY(const int &y_units) const;

    /*!
     * @brief Subtract some units from the x-axis
     *
     * @param x_units the value to be subtracted from the x-axis
     * @return Point the new Point returned
     */
    [[nodiscard]] Point minusX(const int &x_units) const;

    /*!
     * @brief Add @param x_units to the x value of this point and return the updated Point
     *
     * @param x_units the value to be added
     * @return Point the new Point
     */
    [[nodiscard]] Point plusX(const int &x_units) const;

    /*!
     * @brief Add @param y_units to the y value of this point
     *
     * @param y_units the units to be added
     * @return Point the new point with the updated y-value
     */
    [[nodiscard]] Point plusY(const int &y_units) const;

    [[nodiscard]] bool isValid() const;

    int x{}; /*< The x value of a point */
    int y{}; /*< The y value of a point */
    /*!
     * @brief An overloaded ostream operator for printing out a Point
     *
     * @param os the ostream (std::ostream&)
     * @param point The point
     * @return std::ostream& the ostream
     */
    friend std::ostream &operator<<(std::ostream &os, const Point &point);

    /*!
     * @brief Overloaded istream operator for for reading a Point object
     *
     * @param is the istream operator
     * @param point the point
     * @return std::istream& the returned istream
     */
    friend std::istream &operator>>(std::istream &is, Point &point);

};

#endif //HIQ_PROGRAMMING_POINT_H
