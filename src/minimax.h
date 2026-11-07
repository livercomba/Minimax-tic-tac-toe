#ifndef MINIMAX_H
#define MINIMAX_H
#include "game.h"
#include "node.h"

std::pair<Coord, int> mini_max(Game game);
int mini_max_recursive(Game game, bool myTurn, int alpha, int beta);

#endif
