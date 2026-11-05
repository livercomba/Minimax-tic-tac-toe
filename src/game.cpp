#include "game.h"

Game::Game() {
    crossTurn = true;
}

void Game::PlayNext(int x, int y) {
    PlayMove(x, y, crossTurn);
    crossTurn = !crossTurn;
}

 
void Game::PlayMove(int x, int y, bool cross) {
    grid[x][y] = cross ? 1 : 2; 
}


std::string Game::PrintBoard() {
    std::string output {};
    for(int i = 0; i<3; i++) {
        for(int j = 0; j<3; j++) {
            output += std::to_string(grid[i][j]);
        }
    }
    return output;
}
