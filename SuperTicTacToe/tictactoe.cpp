#include "tictactoe.h"

TicTacToe::TicTacToe()
{
    board = Board();
}

Shape TicTacToe::isGameOver()
{
    std::vector<Cell> cells = board.getCells();

    // Horizontal lines
    int i = 0;
    while(i < 9){
        if(cells[i].getShape() == cells[i+1].getShape() &&
            cells[i].getShape() == cells[i+2].getShape()){
            if(cells[i].getShape() != Shape::empty){
                gameIsOver = true;
                return cells[i].getShape();
            }
        }
        i += 3;
    }

    // Vertical lines
    i = 0;
    while( i < 3){
        if(cells[i].getShape() == cells[i+3].getShape() &&
            cells[i].getShape() == cells[i+6].getShape()){
            if(cells[i].getShape() != Shape::empty){
                gameIsOver = true;
                return cells[i].getShape();
            }
        }
        i++;
    }

    // Top-left to Bottom-right diagonal
    if(cells[0].getShape() == cells[4].getShape() &&
        cells[0].getShape() == cells[8].getShape()){
        if(cells[i].getShape() != Shape::empty){
            gameIsOver = true;
            return cells[i].getShape();
        }
    }

    // Top-right to Bottom-Left diagonal
    if(cells[2].getShape() == cells[4].getShape() &&
        cells[2].getShape() == cells[6].getShape()){
        if(cells[i].getShape() != Shape::empty){
            gameIsOver = true;
            return cells[i].getShape();
        }
    }

    return Shape::empty;
}

Board& TicTacToe::getBoard()
{
    return board;
}

bool TicTacToe::getIsGameOver()
{
    return gameIsOver;
}
