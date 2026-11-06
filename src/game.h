#ifndef GAME_H
#define GAME_H

#include <string>
#include <utility>
#include <vector>
#include <iostream>

#include "types.h"
#include "io.h"



class Game {
public:
    short grid[3][3] {0};
    bool crossTurn {};
    Game(); 
    void GameLoop(ConsoleIO& console);

    int PlayNext(Coord coord);
    std::string PrintBoard(bool withCoords = true); 
    int position_number(); 
    Coords next_possible_moves();
    int CheckWin(); 

    private: 
    void PlayMove(int x, int y, bool cross); 
};



#endif
