#ifndef CELL_H
#define CELL_H
#include <iostream>

enum class Shape{
    empty,
    circle,
    cross,
    tie
};

class Cell
{
public:
    Cell();
    Shape getShape();
    void setShape(Shape shape);
    void printCell();
private:
    Shape shape;
};


#endif // CELL_H
