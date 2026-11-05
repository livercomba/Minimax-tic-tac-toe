#ifndef GAME_H
#define GAME_H
#include <string>
class Game {
public:
    unsigned short grid[3][3] {};
    bool crossTurn {};
    Game(); 

    void PlayNext(int x, int y); 

    std::string PrintBoard(); 

private: 
    void PlayMove(int x, int y, bool cross); 


};
#endif
