#include "cell.h"


Cell::Cell()
{
    shape = Shape::empty;
}

void Cell::setShape(Shape shape)
{
    this->shape = shape;
}


