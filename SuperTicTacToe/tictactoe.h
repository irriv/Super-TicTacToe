#ifndef TICTACTOE_H
#define TICTACTOE_H
#include "board.h"

class TicTacToe
{
public:
    TicTacToe();
    Shape isGameOver();
    Board& getBoard();
private:
    Board board;
    Shape winner = Shape::empty;
};

#endif // TICTACTOE_H
