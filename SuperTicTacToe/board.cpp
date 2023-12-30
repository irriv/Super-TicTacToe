#include "board.h"

Board::Board()
{
    cells.reserve(9);
    for(int i=0; i<9; i++){
        cells.push_back(Cell());
    }
}

Cell& Board::getCell(int index)
{
    if(index > -1 && index < 9){ // 0-8 allowed.
        return cells[index];
    }
    else{ // Should never end up in here.
        throw("Index out of bounds");
    }
}

/*
 * Cell is only set if it is empty.
 */
void Board::setCell(int index, Shape shape)
{
    if(index > -1 && index < 9){ // 0-8 allowed.
        if(cells[index].getShape() == Shape::empty){
            cells[index].setShape(shape);
        }
    }
    else{ // Should never end up in here.
        throw("Index out of bounds");
    }
}

const std::vector<Cell>& Board::getCells()
{
    return cells;
}

/*
void Board::printBoard()
{
    for(int i=0; i<9; i++){
        cells[i].printCell();
        std::cout << " ";
        if(i == 8){
            return;
        }
        else if(i == 2 || i == 5){
            std::cout << std::endl << "---------" << std::endl;
        }
        else{
            std::cout << "| ";
        }
    }
}
*/
