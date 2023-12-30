#include "supertictactoe.h"

SuperTicTacToe::SuperTicTacToe()
{
    games.reserve(9);
    for(int i=0; i<9; i++){
        games.push_back(TicTacToe());
    }
}

void SuperTicTacToe::play()
{
    askWhoGoesFirst();
    askGameIndex();
    while(winner == Shape::empty){ // Game loops until it ends.
        gameLoop();
    }
}

/*
 * Asks the player(s) who goes first.
 * This is done when a new SuperTicTacToe game starts.
 * This is done until a valid shape is given.
 */
void SuperTicTacToe::askWhoGoesFirst()
{
    std::string firstShapeStr;
    while(true){
        std::cout << "Who goes first? (X/O): ";
        std::getline(std::cin, firstShapeStr);
        if(firstShapeStr == "X" || firstShapeStr == "x"){
            currentShape = Shape::cross;
            break;
        }
        else if(firstShapeStr == "O" || firstShapeStr == "o" || firstShapeStr == "0"){
            currentShape = Shape::circle;
            break;
        }
        else{
            std::cout << "Invalid input." << std::endl;
        }
    }
}

/*
 * Asks the player which cell they want to fill next.
 * This is done when the turn of a player starts.
 * This is done until a valid 'cellIndex' is given (1-9 excluding indexes of already occupied cells).
 */
void SuperTicTacToe::askCellIndex(int& cellIndex)
{
    std::string cellIndexStr;
    while(true){
        std::cout << "Which cell to fill in game #" << currentGameIndex << "? (1-9): ";
        std::getline(std::cin, cellIndexStr);
        try {
            cellIndex = std::stoi(cellIndexStr);
            if(cellIndex < 1 || cellIndex > 9){
                std::cout << "Index out of bounds." << std::endl;
            }
            else if(cellIndexStr.length() != 1){
                throw(std::exception());
            }
            else if(games[currentGameIndex-1].getBoard().getCell(cellIndex-1).getShape() != Shape::empty){ // Cell is not empty.
                std::cout << "Cell #" << cellIndex << " is already occupied." << std::endl;
            }
            else{
                break;
            }
        }  catch (const std::exception& e) {
            std::cout << "Invalid input." << std::endl;
        }
    }
}

/*
 * Asks the player in which game they want to play next.
 * This is done when the previous 'cellIndex' points to a game that has already ended.
 * This is done until a valid 'gameIndex' is given (1-9 excluding indexes of already ended games).
 */
void SuperTicTacToe::askGameIndex()
{
    std::string gameIndexStr;
    while(true){
        std::cout << "Which game to play at next? (1-9): ";
        std::getline(std::cin, gameIndexStr);
        try {
            currentGameIndex = std::stoi(gameIndexStr);
            if(currentGameIndex < 1 || currentGameIndex > 9){
                std::cout << "Index out of bounds." << std::endl;
            }
            else if(gameIndexStr.length() != 1){
                throw(std::exception());
            }
            else if(games[currentGameIndex-1].isGameOver() != Shape::empty){
                std::cout << "Game is already over at game #" << currentGameIndex << "." << std::endl;
            }
            else{
                break;
            }
        }  catch (const std::exception& e) {
            std::cout << "Invalid input." << std::endl;
        }
    }
}

/*
 * Prints the SuperTicTacToe board.
 * This was difficult.
 */
void SuperTicTacToe::printBoard()
{
    for(int gameRowStart=0; gameRowStart<9; gameRowStart+=3){ // Index of the first TicTacToe game in the horizontal row (0, 3, 6).
        int gameRowEnd = gameRowStart + 3; // End of the game row index (3, 6, 9).
        for(int currentRow=0; currentRow<3; currentRow++){ // Row of the TicTacToe game being printed (0-2).
            for(int gameIndex=gameRowStart; gameIndex<gameRowEnd; gameIndex++){ // Index of the current game being printed (0-2, 3-5, 6-8).
                Board board = games[gameIndex].getBoard();
                for(int cellIndex=0; cellIndex<3; cellIndex++){ // Cell index of the board being printed (0-2).
                    board.getCell(3*currentRow+cellIndex).printCell(); // Row is (0, 3, 6), cellIndex (0, 1, 2).
                    if(cellIndex != 2){ // Print '|' only between the inner cell gaps.
                        std::cout << " | ";
                    }
                    else if(gameIndex != gameRowEnd-1){ // Print '||' in inner gaps of TicTacToe games in the row.
                        std::cout << " || ";
                    }
                    else if(gameIndex == gameRowEnd-1 && currentRow != 2){ // Print line breaks after printing the cells if it is not the last row of the TicTacToe game.
                        std::cout << std::endl;
                    }
                    else if(gameIndex != 8){ // Print horizontal separator in inner gaps of TicTacToe games in the SuperTicTacToe game.
                        std::cout << std::endl <<
                        "===================================" << std::endl;
                    }
                    else{ // Print line break instead of horizontal separator after the whole board is printed.
                        std::cout << std::endl;
                    }
                }
            }
        }
    }
}

void SuperTicTacToe::printTurn()
{
    if(currentShape == Shape::cross){
        std::cout << "Player 1 (Cross) turn!" << std::endl;
    }
    else{
        std::cout << "Player 2 (Circle) turn!" << std::endl;
    }
}

void SuperTicTacToe::printWinner()
{
    if(winner == Shape::cross){
        std::cout << "Player 1 (Cross) wins!" << std::endl;
    }
    else if(winner == Shape::circle){
        std::cout << "Player 2 (Circle) wins!" << std::endl;
    }
    else{
        std::cout << "It's a tie!" << std::endl;
    }
}

void SuperTicTacToe::changeTurn()
{
    if(currentShape == Shape::cross){
        currentShape = Shape::circle;
    }
    else{
        currentShape = Shape::cross;
    }
}

/*
 * The gameplay loop.
 * Cell and game indexes are given by (and shown to) the player in range 1-9.
 * Indexes have to be lowered by 1 when using them because of this.
 * This is to make the playability of the game better.
 */
void SuperTicTacToe::gameLoop()
{
    // Print status of the game.
    printBoard();
    printTurn();

    // Ask player to fill in a cell.
    int cellIndex;
    askCellIndex(cellIndex);
    games[currentGameIndex-1].getBoard().setCell(cellIndex-1, currentShape);

    // Check if the game has ended.
    isGameOver();
    if(winner != Shape::empty){ // SuperTicTacToe game has ended.
        printBoard();
        printWinner();
        return;
    }

    // Check if the game at the new coordinate is not over.
    if(games[cellIndex-1].isGameOver() == Shape::empty){
        currentGameIndex = cellIndex;
        changeTurn();
    }
    else{ // Game was over at the new coordinate. Player chooses coordinate.
        printBoard();
        changeTurn();
        printTurn();
        std::cout <<  "Game is already over at game #" << cellIndex << "." << std::endl;
        askGameIndex();
    }
}

/*
 * Checks if the game has a winner.
 * Returns the winner as a Shape.
 */
void SuperTicTacToe::isGameOver()
{
    // Horizontal lines.
    for(int i=0; i<9; i+=3){
        if(games[i].isGameOver() == games[i+1].isGameOver() &&
            games[i].isGameOver() == games[i+2].isGameOver()){
            if(games[i].isGameOver() != Shape::empty){
                winner = games[i].isGameOver();
            }
        }
    }

    // Vertical lines.
    for(int i=0; i<3; i++){
        if(games[i].isGameOver() == games[i+3].isGameOver() &&
            games[i].isGameOver() == games[i+6].isGameOver()){
            if(games[i].isGameOver() != Shape::empty){
                winner = games[i].isGameOver();
            }
        }
    }

    // Top-left to bottom-right diagonal.
    if(games[0].isGameOver() == games[4].isGameOver() &&
        games[0].isGameOver() == games[8].isGameOver()){
        if(games[0].isGameOver() != Shape::empty){
            winner = games[0].isGameOver();
        }
    }

    // Top-right to bottom-Left diagonal.
    if(games[2].isGameOver() == games[4].isGameOver() &&
        games[2].isGameOver() == games[6].isGameOver()){
        if(games[2].isGameOver() != Shape::empty){
            winner = games[2].isGameOver();
        }
    }

    // Tie check. All cells have to be filled.
    bool tie = true;
    for(TicTacToe& game : games){
        if(game.isGameOver() == Shape::empty){
            tie = false;
        }
    }

    // All cells filled in every game and no winner found.
    if(tie && winner == Shape::empty){
        winner = Shape::tie;
    }
}
