#include "game.h"


int main() {
    Game game;     
    RealIO console;
    //Coords coords = {{1, 2}, {0, 0}, {1,0}, {2,0}, {0, 1}, {1, 1}};
    //StubIO console(coords); 
    game.game_loop(console);

    
       
}
