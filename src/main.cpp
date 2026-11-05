#include "game.h"

#include <iostream>

int main() {
    Game game;    
    for(int i = 0; i<10; i++) 
    {
        std::cout << "What do you wish to play in tic tac toe?";
        game.PrintBoard();
        int x{}, y{};
        std::cin >> x >> y; 
        game.PlayNext(x, y);   
    }
}
