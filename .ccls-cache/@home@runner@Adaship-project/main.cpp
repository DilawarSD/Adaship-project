#include <iostream>
#include <vector>
#include "headers/config.h"
#include "headers/board.h"
#include "headers/boats.h"

int main() {
    // Specify the configuration file
    std::string configFile = "adaship_config.ini";

    
    Config config = Config::readConfig(configFile);

    // Initialize manual placement board
    std::vector<std::vector<char>> manualBoard = config.initializeBoard();

    // Initialize automatic placement board
    std::vector<std::vector<char>> autoBoard = config.initializeBoard();

  std::vector<Boat> boats = config.getBoats();

  // Place ships manually
    for (const auto& boat : boats) {
        Ships::manualPlaceShip(boat, config, manualBoard);
    }

    // Place ships automatically
    for (const auto& boat : boats) {
        Ships::autoPlaceShip(boat, config, autoBoard);
    }

    // Display manual placement board
    std::cout << "Manual Board:\n";
    displayBoard(manualBoard);

    // Display automatic placement board
    std::cout << "\nAutomatic Board:\n";
    displayBoard(autoBoard);

  return 0;
}