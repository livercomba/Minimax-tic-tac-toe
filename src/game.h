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
    void game_loop(ConsoleIO& console);

    int play_next(Coord coord);
    std::string print_board(bool withCoords = true); 
    int position_number(); 
    Coords next_possible_moves();
    int check_win(); 

    private: 
    void announce_winner(const std::string& winner);
    void play_move(int x, int y, bool cross); 
};



#endif
