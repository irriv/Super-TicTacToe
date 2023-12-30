#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "cell.h"

class Board
{
public:
    Board();
    Cell& getCell(int index);
    void setCell(int index, Shape shape);
    const std::vector<Cell>& getCells();
    // void printBoard(); Not in use
private:
   std::vector<Cell> cells;
};

#endif // BOARD_H
