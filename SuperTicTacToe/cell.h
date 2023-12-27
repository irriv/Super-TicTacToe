#ifndef CELL_H
#define CELL_H

enum class Shape{
    empty,
    circle,
    cross
};

class Cell
{
public:
    Cell();
    Shape getShape();
private:
    void setShape(Shape shape);
    Shape shape;
};


#endif // CELL_H
