#ifndef TICTACTOE_H
#define TICTACTOE_H
#include "board.h"

class TicTacToe
{
public:
    TicTacToe();
    Shape& isGameOver();
    Board& getBoard();
private:
    void markWin();
    Board board = Board();
    Shape winner = Shape::empty;
};

#endif // TICTACTOE_H
