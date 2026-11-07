#include "minimax.h"
#include "game.h"
#include <utility>
#include <chrono>

std::pair<Coord, int> mini_max(Game game) {
    auto start = std::chrono::high_resolution_clock::now();
    
    Coord bestMove{};
    int bestScore = 0;
    int score = -10;
    Coords possibleMoves = game.next_possible_moves();
    for(int i = 0; i<possibleMoves.size(); i++) {
        Game CopyGame = game;
        CopyGame.play_next(possibleMoves[i]); 
        score = mini_max_recursive(CopyGame, false, -1, 1);
        if(score >= bestScore) {
            bestMove = possibleMoves[i];
            bestScore = score;
        }
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << "\nMini_max_recursive took: " << elapsed.count() << "ms\n";
    
    
    return {bestMove, 0};
}

int mini_max_recursive(Game game, bool max_turn, int alpha, int beta) {
    int win {game.check_win()};
    if(win != 0) {
        return win;   
    }


    Coords possibleMoves = game.next_possible_moves();
    if(possibleMoves.size() == 0) {
        return 0;
    }

    int val{max_turn ? -1000 : 1000};
    
    for(int i = 0; i<possibleMoves.size(); i++) {
        Game copyGame = game; 

        copyGame.play_next(possibleMoves[i]);
        int temp = mini_max_recursive(copyGame, !max_turn, alpha, beta);
        val = max_turn ? std::max(temp, val) : std::min(temp, val);

        if(max_turn) {
            alpha = std::max(alpha, val);
        }
        else {
            beta = std::min(beta, val);
        }
        
        if(alpha >= beta) {
            return val;
        }
         
    }    
    return val;

}
