#ifndef TICTACTOE_H
#define TICTACTOE_H
#include "board.h"

class TicTacToe
{
public:
    TicTacToe();
    Shape isGameOver();
    Board getBoard();
    bool getIsGameOver();
private:
    Board board;
    bool gameIsOver = false;
};

#endif // TICTACTOE_H
