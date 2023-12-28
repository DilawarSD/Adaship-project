#ifndef GAME_H
#define GAME_H

#include "config.h"
#include "ships.h"
#include "player.h"
#include "computer.h"
#include <iostream> // Include the necessary header for Config class

class Game {
public:
Game(const Config& config);

std::pair<int, int> getUserMoveInput();

std::vector<std::vector<char>> initializeBoard() const;

void play();

void playerMove(std::vector<std::vector<char>>& board);

void computerMove(std::vector<std::vector<char>>& board);

bool checkWin(const std::vector<std::vector<char>>& board) const;

private:
bool isValidMove(int row, int col, const std::vector<std::vector<char>>& board) const;

void manualPlaceAllShips(const std::vector<Boat>& boats, const Config& config, std::vector<std::vector<char>>& board);

void autoPlaceRemainingShips(const std::vector<Boat>& boats, const Config& config, std::vector<std::vector<char>>& board);

void placeShips(std::vector<Boat>& boats, Ships& playerShips, Ships& computerShips, const Config& config);

Ships& getShips();
 
Ships playerShips;

Ships computerShips;

std::vector<std::vector<char>> playerBoard;

std::vector<std::vector<char>> computerBoard;
     
    Config config;
};
#endif