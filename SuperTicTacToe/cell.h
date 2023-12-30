#ifndef CELL_H
#define CELL_H
#include <iostream>

enum class Shape{ // Shape that is in a cell, tie is only used when determining the winner.
    empty,
    circle,
    cross,
    tie
};

class Cell
{
public:
    Cell();
    Shape& getShape();
    void setShape(Shape shape);
    void printCell();
private:
    Shape shape = Shape::empty;
};

#endif // CELL_H
