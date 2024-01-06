#include "../headers/game.h"
#include "../headers/board.h"
#include "../headers/computer.h"
#include "../headers/config.h"
#include "../headers/menu.h"
#include "../headers/player.h"
#include "../headers/ships.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Game::Game(const Config &config) : config(config) { std::srand(std::time(0)); }

std::vector<std::vector<char>> Game::initializeBoard() const {
  return config.initializeBoard();
}

// Player move function with improved error handling
void Game::playerMove(std::vector<std::vector<char>> &board) {
  Player player; // Create an instance of the Player class
  player.playerMove(
      board); // Delegate to the playerMove function in the Player class
}

void Game::computerMove(std::vector<std::vector<char>> &board) {
  Computer computer;
  computer.computerMove(board);
}

bool Game::checkWin(const std::vector<std::vector<char>> &board) const {
  for (const auto &row : board) {
    for (char cell : row) {
      if (cell == 'S') {
        return false; 
      }
    }
  }
  return true; 
}

void Game::placeShips(std::vector<Boat> &boats, Ships &playerShips,
                      Ships &computerShips, const Config &config) {
  // Place ships manually
  playerShips.manualPlaceAllShips(boats, config, playerBoard);
  displayBoard(playerBoard,false);

  for (const auto &boat : boats) {
    computerShips.autoPlaceShip(boat, config, computerBoard);
  }
}

void Game::play() {
  playerBoard = initializeBoard();
  computerBoard = initializeBoard();
  Ships playerShips(true); 
  Ships computerShips(false);
  // Get the list of boats from the configuration
  std::vector<Boat> boats = config.getBoats();
  // Place ships
  placeShips(boats, playerShips, computerShips, config);
  // Player vs Computer gameplay
  while (true) {
    // Player's turn
    std::cout << "Player's turn:" << std::endl;
    displayBoard(playerBoard,false); // Use player's board
    playerMove(computerBoard); // Pass computer's board to playerMove
    // Check if the player has won
    if (checkWin(computerBoard)) {
      displayBoard(
          computerBoard,true); // Display the final state of the computer's board
      std::cout << "Congratulations! You win!" << std::endl;
      break;
    }
    // Computer's turn
    std::cout << "Computer's turn:" << std::endl;
    displayBoard(computerBoard,false); // Use computer's board for display
    computerMove(playerBoard);   // Pass player's board to computerMove
    // Check if the computer has won
    if (checkWin(playerBoard)) {
      displayBoard(
          playerBoard,false); // Display the final state of the player's board
      std::cout << "Computer wins! Better luck next time." << std::endl;
      break;
    }
  }
}
