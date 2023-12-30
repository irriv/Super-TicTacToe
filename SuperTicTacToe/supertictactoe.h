#ifndef SUPERTICTACTOE_H
#define SUPERTICTACTOE_H
#include "tictactoe.h"

class SuperTicTacToe
{
public:
    SuperTicTacToe();
    void play();
private:
    void askWhoGoesFirst();
    void askCellIndex(int& cellIndex);
    void askGameIndex();
    void printBoard();
    void printTurn();
    void printWinner();
    void changeTurn();
    void gameLoop();
    void isGameOver();

    std::vector<TicTacToe> games;
    int currentGameIndex;
    Shape currentShape = Shape::cross;
    Shape winner = Shape::empty;
};

#endif // SUPERTICTACTOE_H
