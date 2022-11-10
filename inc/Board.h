//
// Created by Longho Bernard Che on 2022-11-10.
//

#ifndef HIQ_PROGRAMMING_BOARD_H
#define HIQ_PROGRAMMING_BOARD_H

#include <iostream>
#include <array>
#include "Point.h"
#include "Direction.h"

class Board {
public:
    Board();

    void show(std::ostream &os = std::cout) const;

    void reset();

    void insert(const Point &, char);

private:
    static constexpr ushort ROWS{5};
    static constexpr ushort COLUMNS{5};
    char location[ROWS][COLUMNS]{};

    [[nodiscard]] bool isEdge() const;

    void  transpose();

};


#endif //HIQ_PROGRAMMING_BOARD_H
