#include "../headers/config.h"
#include <iostream>
#include <vector>

void displayBoard(const std::vector<std::vector<char>> &board) {
  std::cout << "   ";
  for (int i = 0; i < board.size(); ++i) {
    char colLabel = 'A' + i;
    std::cout << colLabel << "  ";
  }
  std::cout << "\n";
  for (int i = 0; i < board.size(); ++i) {
    std::cout << "-";
    for (int j = 0; j < board[i].size(); ++j) {
      std::cout << "----";
    }
    std::cout << "\n";
    std::cout << i + 1 << "|";
    for (int j = 0; j < board[i].size(); ++j) {
      std::cout << " " << board[i][j] << "|";
    }
    std::cout << "\n";
  }
  std::cout << "-";
  for (int i = 0; i < board.size(); ++i) {
    std::cout << "----";
  }
  std::cout << "\n";
}
