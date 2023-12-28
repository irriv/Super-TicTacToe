#include "board.h"

Board::Board()
{
    cells.reserve(9);
    for(int i=0; i<9; i++){
        cells.push_back(Cell());
    }
}

void Board::printBoard()
{
    for(int i=0; i<9; i++){
        cells[i].printCell();
        std::cout << " ";
        if(i == 8){
            return;
        }
        else if (i == 2 || i == 5){
            std::cout << std::endl << "---------" << std::endl;
        }
        else{
            std::cout << "| ";
        }
    }
}

Cell Board::getCell(int index)
{
    if (index < 9){
        return cells[index];
    }
    else {
        throw("Index out of bounds");
    }
}

bool Board::setCell(int index, Shape shape)
{
    if(cells[index].getShape() == Shape::empty){
        cells[index].setShape(shape);
        return true;
    }
    return false;
}

std::vector<Cell> Board::getCells()
{
    return cells;
}


