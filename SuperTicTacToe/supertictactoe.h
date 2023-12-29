#ifndef SUPERTICTACTOE_H
#define SUPERTICTACTOE_H
#include "tictactoe.h"
#include <sstream>
#include <limits>

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
    void changeGame();
    void gameLoop();
    void printBoard();
    void isGameOver();

    std::vector<TicTacToe> games;
    int cellIndex = 1;
    int gameIndex;
    Player turn;
    Shape currentShape;
    Shape winner = Shape::empty;
};

#endif // SUPERTICTACTOE_H
