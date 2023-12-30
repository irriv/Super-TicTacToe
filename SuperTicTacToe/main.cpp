#include <iostream>
#include "supertictactoe.h"

using namespace std;

int main()
{
    while(true){
        SuperTicTacToe game = SuperTicTacToe();
        std::cout << "SuperTicTacToe game starts!" << std::endl;
        game.play(); // Start the game.

        // Ask player(s) if they want to replay the game.
        std::string replay;
        while(true){
            std::cout << "Play again? (Y/N): ";
            std::getline(std::cin, replay);
            if(replay == "Y" || replay == "y"){
                break;
            }
            else if(replay == "N" || replay == "n"){
                break;
            }
            else{
                std::cout << "Invalid input." << std::endl;
            }
        }

        if(replay == "N" || replay == "n"){ // Exit the program.
            break;
        }
    }
    return 0;
}
