#include "tictactoe.h"

TicTacToe::TicTacToe()
{
}

Board& TicTacToe::getBoard()
{
    return board;
}

/*
 * Checks if the game has a winner.
 * Returns the winner as a Shape.
 */
Shape& TicTacToe::isGameOver()
{
    if(winner != Shape::empty){
        return winner;
    }

    std::vector<Cell> cells = board.getCells();

    // Horizontal lines.
    for(int i=0; i<9; i+=3){
        if(cells[i].getShape() == cells[i+1].getShape() &&
            cells[i].getShape() == cells[i+2].getShape()){
            if(cells[i].getShape() != Shape::empty){
                winner = cells[i].getShape();
            }
        }
    }

    // Vertical lines.
    for(int i=0; i<3; i++){
        if(cells[i].getShape() == cells[i+3].getShape() &&
            cells[i].getShape() == cells[i+6].getShape()){
            if(cells[i].getShape() != Shape::empty){
                winner = cells[i].getShape();
            }
        }
    }

    // Top-left to bottom-right diagonal.
    if(cells[0].getShape() == cells[4].getShape() &&
        cells[0].getShape() == cells[8].getShape()){
        if(cells[0].getShape() != Shape::empty){
            winner = cells[0].getShape();
        }
    }

    // Top-right to bottom-Left diagonal.
    if(cells[2].getShape() == cells[4].getShape() &&
        cells[2].getShape() == cells[6].getShape()){
        if(cells[2].getShape() != Shape::empty){
            winner = cells[2].getShape();
        }
    }

    // Tie check. All cells have to be filled.
    bool tie = true;
    for(Cell& cell : cells){
        if(cell.getShape() == Shape::empty){
            tie = false;
        }
    }

    if(tie && winner == Shape::empty){ // All cells filled and no winner found.
        //std::cout << "It's a tie on this board!" << std::endl;
        winner = Shape::tie;
        return winner;
    }
    else if(winner == Shape::cross){
        //std::cout << "Player 1 (Cross) wins on this board!" << std::endl;
        return winner;
    }
    else if(winner == Shape::circle){
        //std::cout << "Player 2 (Circle) wins on this board!" << std::endl;
        return winner;
    }
    else{ // No winner found, return Shape::empty.
        return winner;
    }
}
