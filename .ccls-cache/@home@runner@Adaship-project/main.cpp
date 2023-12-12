#include <iostream>
#include <vector>
#include "headers/config.h"
#include "headers/board.h"
#include "headers/boats.h"

int main() {
    // Specify the configuration file
    std::string configFile = "adaship_config.ini";

    
    Config config = Config::readConfig(configFile);

    // Initialize and display the game board
    std::vector<std::vector<char>> board = config.initializeBoard();

  std::vector<Boat> boats = config.getBoats();

  for (const auto& boat : boats) {
      Ships::manualPlaceShip(boat, config, board);
  }

    // Display the board
    displayBoard(board);

  return 0;
}