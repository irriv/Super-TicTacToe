#include "supertictactoe.h"

SuperTicTacToe::SuperTicTacToe()
{
    games.reserve(9);
    for(int i=0; i<9; i++){
        games.push_back(TicTacToe());
    }
    turn = Player::player1;
    currentShape = Shape::cross;
    gameIndex = 5;
}

void SuperTicTacToe::play()
{
    while(winner == Shape::empty){
        gameLoop();
    }
}

void SuperTicTacToe::printTurn()
{
    if (turn == Player::player1){
        std::cout << "Player 1 (Cross) turn!" << std::endl;
    }
    else{
        std::cout << "Player 2 (Circle) turn!" << std::endl;
    }
}

void SuperTicTacToe::changeTurn()
{
    if(turn == Player::player1){
        turn = Player::player2;
        currentShape = Shape::circle;
    }
    else{
        turn = Player::player1;
        currentShape = Shape::cross;
    }
}

void SuperTicTacToe::gameLoop()
{
    printBoard();
    printTurn();

    // Ask player to fill in a cell.
    int cellIndex = 0;
    std::string cellNumber;
    while(cellIndex < 1 || cellIndex > 9){
        std::cout << "Which cell to fill in game #" << gameIndex << "? (1-9): ";
        std::getline(std::cin, cellNumber);

        try {
            cellIndex = std::stoi(cellNumber);
            if(cellIndex < 1 || cellIndex > 9){
                std::cout << "Index out of bounds." << std::endl;
            }
            if(cellNumber.length() != 1){
                throw(std::exception());
            }
            else{
                if(!games[gameIndex-1].getBoard().setCell(cellIndex-1, currentShape)){
                    std::cout << "Cell #" << cellIndex << " is already occupied." << std::endl;
                    cellIndex = 0;
                }
            }
        }  catch (const std::exception& e) {
            std::cout << "Invalid input." << std::endl;
            cellIndex = 0;
        }
    }

    // Is super game over?
    isGameOver();
    if(winner != Shape::empty){
        printBoard();
        if(turn == Player::player1){
            std::cout << "Player 1 (Cross) wins!" << std::endl;
        }
        else{
            std::cout << "Player 2 (Circle) wins!" << std::endl;
        }
        return;
    }

    // Check if the game at the new coordinate is not over
    if(games[cellIndex-1].isGameOver() == Shape::empty){
        gameIndex = cellIndex;
        changeTurn();
    }
    else{ // Player chooses coordinate
        printBoard();
        changeTurn();
        printTurn();
        std::cout <<  "Game is already over at game #" << cellIndex << "." << std::endl;
        gameIndex = 0;
        std::string nextGame;
        while(gameIndex < 1 || gameIndex > 9){
            std::cout << "Which game to play at next? (1-9): ";
            std::getline(std::cin, nextGame);

            // Convert input to int
            try {
                gameIndex = std::stoi(nextGame);
                if(gameIndex < 1 || gameIndex > 9){
                    std::cout << "Index out of bounds." << std::endl;
                }
                if(nextGame.length() != 1){
                    throw(std::exception());
                }
                if(games[gameIndex-1].isGameOver() != Shape::empty){
                    std::cout << "Game is already over at game #" << gameIndex << "." << std::endl;
                    gameIndex = 0;
                }
            }  catch (const std::exception& e) {
                std::cout << "Invalid input." << std::endl;
                gameIndex = 0;
            }
        }
    }
}

void SuperTicTacToe::printBoard()
{
    for(int firstGameInRowIndex=0; firstGameInRowIndex<9; firstGameInRowIndex+=3){
        int toGame = firstGameInRowIndex + 3;
        for(int boardRow=0; boardRow<3; boardRow++){
            for(int currentGame=firstGameInRowIndex; currentGame < toGame; currentGame++){
                Board board = games[currentGame].getBoard();
                for(int cellIndex=0; cellIndex<3; cellIndex++){
                    board.getCell(3*boardRow+cellIndex).printCell();
                    if(cellIndex != 2){
                        std::cout << " | ";
                    }
                    else if(currentGame != toGame-1){
                        std::cout << " || ";
                    }
                    else if(currentGame == toGame-1 && boardRow != 2){
                        std::cout << std::endl;
                    }
                    else if(currentGame != 8){
                        std::cout << std::endl <<
                        "===================================" << std::endl;
                    }
                    else{
                        std::cout << std::endl;
                    }
                }
            }
        }
    }
}

void SuperTicTacToe::isGameOver()
{
    // Horizontal lines
    int i = 0;
    while(i < 9){
        if(games[i].isGameOver() == games[i+1].isGameOver() &&
            games[i].isGameOver() == games[i+2].isGameOver()){
            if(games[i].isGameOver() != Shape::empty){
                winner = games[i].isGameOver();
            }
        }
        i += 3;
    }

    // Vertical lines
    i = 0;
    while(i < 3){
        if(games[i].isGameOver() == games[i+3].isGameOver() &&
            games[i].isGameOver() == games[i+6].isGameOver()){
            if(games[i].isGameOver() != Shape::empty){
                winner = games[i].isGameOver();
            }
        }
        i++;
    }

    // Top-left to Bottom-right diagonal
    if(games[0].isGameOver() == games[4].isGameOver() &&
        games[0].isGameOver() == games[8].isGameOver()){
        if(games[0].isGameOver() != Shape::empty){
            winner = games[0].isGameOver();
        }
    }

    // Top-right to Bottom-Left diagonal
    if(games[2].isGameOver() == games[4].isGameOver() &&
        games[2].isGameOver() == games[6].isGameOver()){
        if(games[2].isGameOver() != Shape::empty){
            winner = games[2].isGameOver();
        }
    }
}
