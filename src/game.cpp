#include "game.h"
#include "minimax.h"
Game::Game() {
    crossTurn = true;
}


void Game::game_loop(ConsoleIO& console) {
    for(int i = 0;i<9;i++) 
    {
        std::cout << "What is your move?(y, x)\n" << print_board();
        switch (play_next(console.read())) {
            case -1:
                announce_winner("X");    
            return;
            case 1:
                announce_winner("O");
                return; 
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

void Game::announce_winner(const std::string& winner) {
    std::cout << "------------------\n";
    std::cout << "\n\n"<< winner << " wins:\n\n";
    std::cout << "------------------\n";
    std::cout << print_board(false);
    std::cout << "------------------\n";
}

int Game::play_next(Coord coord) {
    if(coord == std::make_pair(-1, -1)) {
        return -2;
    }
    if(grid[coord.first][coord.second] != 0) {
        std::cerr << "illegal move";
        throw "Illegal move";
    }
    play_move(coord.first, coord.second, crossTurn);
    crossTurn = !crossTurn;
    return check_win();
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

void Game::play_move(int y, int x, bool cross) {
    grid[y][x] = cross ? -1 : 1; 
}

int Game::check_win() {
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

std::string Game::print_board(bool withCoords) {
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
            case -1:
                output += 'X';
                break;
            case 1:
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



