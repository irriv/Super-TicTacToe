#include "tictactoe.h"

TicTacToe::TicTacToe()
{
    board = Board();
}

Shape TicTacToe::isGameOver()
{
    if(winner != Shape::empty){
        return winner;
    }

    std::vector<Cell> cells = board.getCells();

    // Horizontal lines
    int i = 0;
    while(i < 9){
        if(cells[i].getShape() == cells[i+1].getShape() &&
            cells[i].getShape() == cells[i+2].getShape()){
            if(cells[i].getShape() != Shape::empty){
                winner = cells[i].getShape();
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
                winner = cells[i].getShape();
            }
        }
        i++;
    }

    // Top-left to Bottom-right diagonal
    if(cells[0].getShape() == cells[4].getShape() &&
        cells[0].getShape() == cells[8].getShape()){
        if(cells[0].getShape() != Shape::empty){
            winner = cells[0].getShape();
        }
    }

    // Top-right to Bottom-Left diagonal
    if(cells[2].getShape() == cells[4].getShape() &&
        cells[2].getShape() == cells[6].getShape()){
        if(cells[2].getShape() != Shape::empty){
            winner = cells[2].getShape();
        }
    }

    bool tie = true;
    for(Cell& cell : cells){
        if(cell.getShape() == Shape::empty){
            tie = false;
        }
    }

    if(tie && winner == Shape::empty){
        std::cout << "It's a tie on this board!" << std::endl;
        winner = Shape::tie;
        return winner;
    }
    else if(winner == Shape::cross){
        std::cout << "Player 1 (Cross) wins on this board!" << std::endl;
        return winner;
    }
    else if(winner == Shape::circle){
        std::cout << "Player 2 (Circle) wins on this board!" << std::endl;
        return winner;
    }
    else{
        return Shape::empty;
    }
}

Board& TicTacToe::getBoard()
{
    return board;
}
