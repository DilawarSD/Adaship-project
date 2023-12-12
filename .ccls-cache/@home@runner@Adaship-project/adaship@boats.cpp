#include <iostream>
#include "../headers/board.h" 
#include "../headers/boats.h"
#include <vector>
#include <limits>

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

    std::cout << "Enter the placement for " << boat.name << " (size " << size << "): ";

    // Get starting position
    std::string userInput;
    std::cout << "Enter starting position (e.g., A1): ";
    std::cin >> userInput;

    char userInputColumn = toupper(userInput[0]);  // Convert to uppercase for consistency
    int userInputRow = std::stoi(userInput.substr(1));  // Extract the row as an integer

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
    } else if ((orientation == 'V' || orientation == 'v') && isValidPlacement(startRowIndex, startColIndex, size, false, board)) {
        // Update the board for vertical placement
        for (int i = 0; i < size; ++i) {
            board[startRowIndex + i][startColIndex] = 'S';  // Use 'S' to represent the ship
        }
    } else {
        std::cout << "Invalid placement. Please try again." << std::endl;
        manualPlaceShip(boat, config, board);  // Retry placement
        return;  // Return to avoid displaying the board if placement is invalid
    }

    // Display the updated board
    displayBoard(board);
}