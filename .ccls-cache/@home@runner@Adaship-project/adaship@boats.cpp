#include <iostream>
#include "../headers/board.h" 
#include "../headers/boats.h"
#include "../headers/config.h"
#include "../headers/menu.h"
#include <vector>
#include <limits>
#include <random>

Ships::Ships(bool isPlayer) : isPlayer(isPlayer) {
    // Initialize other member variables and perform other setup if needed
}

bool Ships::isValidPlacement(int startRow, int startCol, int size, bool isHorizontal, const std::vector<std::vector<char>>& board) {
    // Check if the placement is within the bounds of the board
    if (startRow < 0 || startRow >= board.size() || startCol < 0 || startCol >= board[0].size()) {
        return false;  // Placement is out of bounds
    }

    // Check if the ship fits within the board
    if (isHorizontal) {
        if (startCol + size > board[0].size()) {
            return false;  // Ship goes beyond the right edge of the board
        }
    } else {
        if (startRow + size > board.size()) {
            return false;  // Ship goes beyond the bottom edge of the board
        }
    }

    // Check if the placement overlaps with other ships
    for (int i = 0; i < size; ++i) {
        if (isHorizontal) {
            if (board[startRow][startCol + i] != ' ') {
                return false;  // Overlapping with another ship
            }
        } else {
            if (board[startRow + i][startCol] != ' ') {
                return false;  // Overlapping with another ship
            }
        }
    }

    return true; 
}

void Ships::manualPlaceShip(const Boat& boat, const Config& config, std::vector<std::vector<char>>& board) {
    int startRowIndex, startColIndex;
    int size = boat.size;  // Use the boat size

    while (true) {
        std::cout << "Enter the placement for " << boat.name << " (size " << size << "): ";
        // Get starting position
        std::string userInput;
        std::cout << "Enter starting position (e.g., A1): ";
        std::cin >> userInput;
        // Validate input format
        if (userInput.size() < 2 || !std::isalpha(userInput[0]) || !std::isdigit(userInput[1])) {
            std::cout << "Invalid input format. Please enter a valid starting position." << std::endl;
            continue;  // Go to the next iteration of the loop to allow the user to re-enter
        }

        char userInputColumn = toupper(userInput[0]);  // Convert to uppercase for consistency
        int userInputRow = userInput[1] - '0';  // Convert the second character to an integer
        // Adjust the row index to match zero-based indexing
        startRowIndex = userInputRow - 1;
        // Convert the starting column to an index
        startColIndex = userInputColumn - 'A';
        // Get orientation
        char orientation;
        std::cout << "Enter orientation (H for horizontal, V for vertical): ";
        std::cin >> orientation;
        // Check if the placement is valid
        if ((orientation == 'H' || orientation == 'h') && isValidPlacement(startRowIndex, startColIndex, size, true, board)) {
            // Update the board for horizontal placement
            for (int i = 0; i < size; ++i) {
                board[startRowIndex][startColIndex + i] = 'S';  // Use 'S' to represent the ship
            }
            break;  // Exit the loop if placement is valid
        } else if ((orientation == 'V' || orientation == 'v') && isValidPlacement(startRowIndex, startColIndex, size, false, board)) {
            // Update the board for vertical placement
            for (int i = 0; i < size; ++i) {
                board[startRowIndex + i][startColIndex] = 'S';  // Use 'S' to represent the ship
            }
            break;  // Exit the loop if placement is valid
        } else {
            std::cout << "Invalid placement. Please try again." << std::endl;
        }
    }
}

void Ships::autoPlaceShip(const Boat& boat, const Config& config, std::vector<std::vector<char>>& board) {
  int size = boat.size;
  int startRow, startCol;
  bool isHorizontal;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, config.boardSize - 1);
  std::uniform_int_distribution<> orientation(0, 1);

  do {
      // Randomly choose starting row and column
      startRow = dis(gen);
      startCol = dis(gen);

      // Randomly choose orientation (horizontal or vertical)
      isHorizontal = orientation(gen) == 0;

  } while (!isValidPlacement(startRow, startCol, size, isHorizontal, board));

  // Update the board based on the randomly chosen valid position and orientation
  for (int i = 0; i < size; ++i) {
      if (isHorizontal) {
          board[startRow][startCol + i] = 'S';  // Use 'S' to represent the ship
      } else {
          board[startRow + i][startCol] = 'S';  // Use 'S' to represent the ship
      }
  }

  //displayBoard(board);
}
