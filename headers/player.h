#ifndef PLAYER_H
#define PLAYER_H

#include "game.h"
#include "board.h"
#include "config.h"
#include "ships.h"
#include <vector>

class Player {
public:
    Player();  
    void playerMove(std::vector<std::vector<char>>& board);

private:
    int playerHits;
    int playerMisses;
};

#endif  