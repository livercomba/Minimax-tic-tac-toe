#include "minimax.h"
#include "game.h"
#include <utility>
#include <chrono>

std::pair<Coord, int> mini_max(Game game) {
    Coord move{std::make_pair(-1, -1)};
    auto start = std::chrono::high_resolution_clock::now();
    std::pair<Coord, int> returnValue = mini_max_recursive(game, true, move);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << "\nMini_max_recursive took: " << elapsed.count() << "ms\n";
    return returnValue;
}

std::pair<Coord, int> mini_max_recursive(Game game, bool myTurn, Coord move) {
    int win {game.CheckWin()};
    if(win != 0) {
        //std::cout << "Victory found:" << win << "\n" << game.PrintBoard(false);
        return {move, win};   
    }

    Coords possibleMoves = game.next_possible_moves();
    if(possibleMoves.size() == 0) {
        return {move, 0};
    }

    Coord bestMove;
    int val{myTurn ? 1000 : -1000};
    
    for(int i = 0; i<possibleMoves.size(); i++) {
        Game copyGame = game; 
        Coord copyMove{};
        if(move.first == -1 && move.second == -1) {
            copyMove = possibleMoves[i];
        }
        else {
            copyMove = move;
        }



        copyGame.PlayNext(possibleMoves[i]);
        std::pair<Coord, int> temp = mini_max_recursive(copyGame, !myTurn, copyMove);
        if(myTurn) {
            if(temp.second <= val) {
                val = temp.second;
                bestMove = temp.first;
            }
        }
        else {
            if(temp.second >= val) {
                val = temp.second;
                bestMove = temp.first;
            }
        }
                 
    }    
    return {bestMove, val};

}
