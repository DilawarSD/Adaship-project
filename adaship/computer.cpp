#include "../headers/computer.h"
#include "../headers/board.h"
#include "../headers/config.h"
#include "../headers/game.h"
#include "../headers/menu.h"
#include "../headers/player.h"
#include "../headers/ships.h"
#include <ctime>
#include <iostream>

Computer::Computer() { std::srand(std::time(0)); }

void Computer::computerMove(std::vector<std::vector<char>> &board) {
  // Seed for random number generation
  int row, col;
  // Generate random moves without checking validity
  row = std::rand() % board.size();
  col = std::rand() % board[0].size();
  // Process the move
  if (board[row][col] == 'S') {
    std::cout << "Computer hit your ship!" << std::endl;
    computerHits++;
    board[row][col] = 'X'; 
  } else {
    std::cout << "Computer missed." << std::endl;
    computerMisses++;
    board[row][col] = 'O'; 
  }
}