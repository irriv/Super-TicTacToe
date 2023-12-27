#include "supertictactoe.h"

SuperTicTacToe::SuperTicTacToe()
{
    games.reserve(9);
    for(int i=0; i<9; i++){
        games[i] = TicTacToe();
    }
    turn = Player::player1;
    currentShape = Shape::cross;
    currentGame = &games[5];
}

void SuperTicTacToe::play()
{
    while(!gameOver){
        playerInput();
    }
}

void SuperTicTacToe::printTurn()
{
    if (turn == Player::player1){
        std::cout << "Player 1's turn!" << std::endl;
    }
    else{
        std::cout << "Player 2's turn!" << std::endl;
    }
}

void SuperTicTacToe::changeTurn()
{
    turn = Player::player2;
}

void SuperTicTacToe::playerInput()
{
    printTurn();
    // Player picks a coordinate and the cell is set.
    index = 0;
    std::string line;
    while(index < 1 || index > 9){
        std::cout << "Which cell to fill in? (1-9): ";
        std::getline(std::cin, line);
        std::stringstream ss(line);
        // Convert input to int
        if (ss >> index){
            // Success
            if (ss.eof()){
                if(!currentGame->getBoard().setCell(index, currentShape)){
                    std::cout << "Cell is already occupied." << std::endl;
                }
                else{
                    break;
                }
            }
        }
        else{
            std::cout << "Invalid input." << std::endl;
        }
    }

    const Shape& result = currentGame->isGameOver();

    // TODO: Print the goddam board maan

    // Game is over
    if(result != Shape::empty){
        if(turn == Player::player1){
            std::cout << "Cross wins!" << std::endl;
        }
        else{
            std::cout << "Circle wins!" << std::endl;
        }
    }
    else{
        // Check if the game at the coordinate is not over
        if(!games[index].getIsGameOver()){
            currentGame = &games[index];
        }
        else{
            // Player chooses coordinate
            index = 0;
            std::string line;
            while(index < 1 || index > 9){
                std::cout << "Which game to play next? (1-9): ";
                std::getline(std::cin, line);
                std::stringstream ss(line);
                // Convert input to int
                if (ss >> index){
                    // Success
                    if (ss.eof()){
                        if(!games[index].getIsGameOver()){
                            break;
                        }
                        else{
                            std::cout << "Game is already over at " << index << std::endl;
                        }
                    }
                }
                else{
                    std::cout << "Invalid input." << std::endl;
                }
            }
            changeTurn();
        }
    }
}


