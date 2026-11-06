#include "game.h"
#include "minimax.h"
Game::Game() {
    crossTurn = true;
}


void Game::GameLoop(ConsoleIO& console) {
    for(int i = 0;i<10;i++) 
    {
        std::cout << "What is your move?(y, x)\n" << PrintBoard();
        switch (PlayNext(console.read())) {
            case 1:
                std::cout << "\n\nX wins:\n\n";
                std::cout << PrintBoard(false);
            return;
            case -1:
                std::cout << "\n\nO wins:\n\n";
                std::cout << PrintBoard(false);
                return; 
            case -2:
                break;
            default:
                if(i%2 == 0) {
                    // circle turn
                    std::pair<Coord, int> minMax = mini_max(*this);

                    std::cout << "MinMaxVal: " << minMax.second << "\n"; 
                    std::cout << "Machine plays: \n" << minMax.first.first << "," << minMax.first.second << "\n"; 
      
                }
                break;
        }
    }
    

}

int Game::PlayNext(Coord coord) {
    if(coord == std::make_pair(-1, -1)) {
        return -2;
    }
    PlayMove(coord.first, coord.second, crossTurn);
    crossTurn = !crossTurn;
    return CheckWin();
}


int Game::position_number() {
    int posIndex{0};
    int p{0};
    int val{};
    for(int i = 0; i<3; i++) {
        for(int j = 0; j<3; j++) {
            val = grid[i][j];
            if(val < 0){
                val = 2;
            }
            posIndex += val*(int)pow(3, p);
            p++;    
        }
    }
    return posIndex;
}
 
Coords Game::next_possible_moves() {
    Coords emptyCells;
    
    for(int i = 0; i<3; i++ ) {
        for(int j = 0; j<3; j++) {
            if(grid[i][j] == 0) {
               emptyCells.push_back({i, j}); 
            }
        }
    }
    return emptyCells; 
}

void Game::PlayMove(int y, int x, bool cross) {
    grid[y][x] = cross ? 1 : -1; 
}

int Game::CheckWin() {

    // Rows
    for(int i = 0; i<3; i++) {
        if(abs(grid[i][0] + grid[i][1] + grid[i][2]) >=3) 
        {
            return grid[i][0];
        }
    } 
    // Columns 
    for(int i = 0; i<3; i++) {
        if(abs(grid[0][i] + grid[1][i] + grid[2][i]) >=3) 
        {
            return grid[0][i];
        }
    }
    //Diagonals
    if(abs(grid[0][0] + grid[1][1] + grid[2][2]) >= 3) {
        return grid[0][0];
    }
    if(abs(grid[2][0] + grid[1][1] + grid[0][2]) >= 3) {
        return grid[2][0];
    }
    
    return 0;
}
std::string Game::PrintBoard(bool withCoords) {
    std::string output {};
    if(withCoords) {
        output = "  0 1 2\n";
    }
    for(int i = 0; i<3; i++) {
        if(withCoords) {
            output += std::to_string(i) + " ";
        }
        for(int j = 0; j<3; j++) {
            switch (grid[i][j]) {
            case 1:
                output += 'X';
                break;
            case -1:
                output += 'O';
                break;
            default:
                output += '*';
                break;
            };
            output += " ";
        }
        output += "\n";
    }
    return output;
}



