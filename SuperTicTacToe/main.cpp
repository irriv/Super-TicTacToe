#include <iostream>
#include "supertictactoe.h"

using namespace std;

int main()
{
    while (true){
        SuperTicTacToe game = SuperTicTacToe();
        std::cout << "SuperTicTacToe game starts!" << std::endl;
        game.play();
        std::string replay;
        while (true){
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
        if(replay == "N" || replay == "n"){
            break;
        }
    }
    return 0;
}
