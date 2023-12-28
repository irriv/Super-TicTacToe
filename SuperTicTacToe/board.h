#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "cell.h"
#include <iostream>

class Board
{
public:
    Board();
    void printBoard();
    Cell getCell(int index);
    bool setCell(int index, Shape shape);
    std::vector<Cell> getCells();
private:
   std::vector<Cell> cells;
};

#endif // BOARD_H
