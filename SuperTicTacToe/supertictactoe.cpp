#include "supertictactoe.h"

SuperTicTacToe::SuperTicTacToe()
{
    games.reserve(9);
    for(int i=0; i<9; i++){
        games.push_back(TicTacToe());
    }
    turn = Player::player1;
    currentShape = Shape::cross;
    currentGame = games[5];
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
    if(turn == Player::player1){
        turn = Player::player2;
        currentShape = Shape::circle;
    }
    else{
        turn = Player::player1;
        currentShape = Shape::cross;
    }
}

void SuperTicTacToe::playerInput()
{
    printTurn();
    printBoard();
    // Player picks a coordinate and the cell is set.

    int cellIndex = 0;
    std::string line;
    while(cellIndex < 1 || cellIndex > 9){
        std::cout << "Which cell to fill in? (1-9): ";
        std::getline(std::cin, line); // This does not work.
        std::stringstream ss(line);
        // Convert input to int
        if (ss >> cellIndex){
            // Success
            if (ss.eof()){
                if(!currentGame.getBoard().setCell(cellIndex, currentShape)){
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

    const Shape& result = currentGame.isGameOver();

    // Game is over
    if(result != Shape::empty){
        gameOver = true;
        if(turn == Player::player1){
            std::cout << "Cross wins!" << std::endl;
        }
        else{
            std::cout << "Circle wins!" << std::endl;
        }
    }
    else{
        int cellIndex = 0;
        // Check if the game at the coordinate is not over
        if(!games[cellIndex].getIsGameOver()){
            currentGame = games[cellIndex];
        }
        else{
            // Player chooses coordinate
            gameIndex = 0;
            std::string line;
            while(gameIndex < 1 || gameIndex > 9){
                std::cout << "Which game to play at next? (1-9): ";
                std::getline(std::cin, line);
                std::stringstream ss(line);
                // Convert input to int
                if (ss >> gameIndex){
                    // Success
                    if (ss.eof()){
                        gameIndex--;
                        if(!games[gameIndex].getIsGameOver()){
                            break;
                        }
                        else{
                            std::cout << "Game is already over at " << gameIndex+1 << std::endl;
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
