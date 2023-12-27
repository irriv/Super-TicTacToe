#include "cell.h"

Cell::Cell()
{
    shape = Shape::empty;
}

Shape Cell::getShape()
{
    return shape;
}

void Cell::setShape(Shape shape)
{
    this->shape = shape;
}

void Cell::printCell()
{
    switch(shape){
    case Shape::cross:
        std::cout << "X";
        break;
    case Shape::circle:
        std::cout << "O";
        break;
    default:
        std::cout << " ";
        break;
    }
}
