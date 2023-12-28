#ifndef SUPERTICTACTOE_H
#define SUPERTICTACTOE_H
#include "tictactoe.h"
#include <sstream>

enum class Player{
    player1,
    player2
};

class SuperTicTacToe
{
public:
    SuperTicTacToe();
    void play();
private:
    void printTurn();
    void changeTurn();
    void playerInput();
    void printBoard();

    std::vector<TicTacToe> games;
    TicTacToe currentGame;
    Player turn;
    Shape currentShape;
    int gameIndex;
    bool gameOver;
};

#endif // SUPERTICTACTOE_H
