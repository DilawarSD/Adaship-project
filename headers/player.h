#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"
#include "config.h"
#include "game.h"
#include "ships.h"
#include <vector>

class Player {
public:
  Player();
  void playerMove(std::vector<std::vector<char>> &board);
  void getMoveFromUser(int& row, int& col, const std::vector<std::vector<char>>& board) const;

private:
  int playerHits;
  int playerMisses;
};

#endif