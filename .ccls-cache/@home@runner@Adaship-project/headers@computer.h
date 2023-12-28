#ifndef COMPUTER_H
#define COMPUTER_H

#include <vector>
#include "game.h"
#include "player.h"
#include "board.h"
#include "ships.h"
#include "config.h"

class Computer {
public:
Computer();
    bool isValidMove(int row, int col, const std::vector<std::vector<char>>& board) const;
void computerMove(std::vector<std::vector<char>>& board);

private:
int computerHits;
int computerMisses;
};

#endif