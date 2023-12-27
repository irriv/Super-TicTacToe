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

    std::vector<TicTacToe> games;
    TicTacToe* currentGame = nullptr;
    Player turn;
    Shape currentShape;
    int index;
    bool gameOver;
};

#endif // SUPERTICTACTOE_H
