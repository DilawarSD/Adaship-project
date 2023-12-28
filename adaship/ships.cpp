#include <iostream>
#include "../headers/board.h" 
#include "../headers/ships.h"
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

    char shipSymbol = (isPlayer) ? 'S' : 'S';  // Use 'S' for player's ships
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
            board[startRow][startCol + i] = shipSymbol;
        } else {
            board[startRow + i][startCol] = shipSymbol;
        }
    }
}

void Ships::manualPlaceAllShips(const std::vector<Boat>& boats, const Config& config, std::vector<std::vector<char>>& board) {
    if (isPlayer) {
        char manualPlaceChoice;
        char resetChoice;

        do {
            // Ask if the user wants to manually place ships
            std::cout << "Do you want to manually place ships? (Select No for autoplacing) (Y/N): ";
            std::cin >> manualPlaceChoice;

            // Validate the input
            while (toupper(manualPlaceChoice) != 'Y' && toupper(manualPlaceChoice) != 'N') {
                std::cout << "Invalid choice. Please enter 'Y' or 'N': ";
                std::cin >> manualPlaceChoice;
            }

            // Check if the user wants to manually place ships
            if (toupper(manualPlaceChoice) == 'Y') {
                for (size_t i = 0; i < boats.size(); ++i) {
                    // Ask if the user wants to place the next ship (skip for the first iteration)
                    if (i > 0) {
                        std::cout << "Do you want to manually place the next ship? (Y/N): ";
                        std::cin >> manualPlaceChoice;
                        // Validate the input
                        while (toupper(manualPlaceChoice) != 'Y' && toupper(manualPlaceChoice) != 'N') {
                            std::cout << "Invalid choice. Please enter 'Y' or 'N': ";
                            std::cin >> manualPlaceChoice;
                        }
                    }

                    // Check if the user wants to manually place the ship
                    if (toupper(manualPlaceChoice) == 'Y') {
                        manualPlaceShip(boats[i], config, board);
                    } else {
                        autoPlaceShip(boats[i], config, board);
                    }

                    // Display the board after each ship placement
                    displayBoard(board);
                }
            } else {
                // Auto-placement for all ships
                for (size_t i = 0; i < boats.size(); ++i) {
                    autoPlaceShip(boats[i], config, board);
                    // Display the board after each ship placement
                    displayBoard(board);
                }
            }

            // Ask if the player wants to reset the board
            std::cout << "Do you want to reset the board and replace the ships? (Y/N): ";
            std::cin >> resetChoice;

            // Validate the input
            while (toupper(resetChoice) != 'Y' && toupper(resetChoice) != 'N') {
                std::cout << "Invalid choice. Please enter 'Y' or 'N': ";
                std::cin >> resetChoice;
            }

            if (toupper(resetChoice) == 'Y') {
                // Reset the board
                resetShipboard(board);
            }

        } while (toupper(resetChoice) == 'Y');
    }
}

bool Ships::isShipPlaced(const Boat& boat, const std::vector<std::vector<char>>& board) {
    // Check if the entire ship is already placed on the board
    int shipSize = boat.size;
    int count = 0;

    for (const auto& row : board) {
        for (const auto& cell : row) {
            if (cell == boat.name[0]) {
                count++;
            }
        }
    }
    return count >= shipSize;  // Ship is considered placed if at least its size number of cells are found
}

bool Ships::allShipPlaced(const std::vector<Boat>& boats, const std::vector<std::vector<char>>& board) {
    for (const auto& boat : boats) {
        if (!isShipPlaced(boat, board)) {
            return false;  // At least one ship is not placed
        }
    }
    return true;  // All ships are placed
}

void Ships::resetShipboard(std::vector<std::vector<char>>& board) {
    for (auto& row : board) {
        for (auto& cell : row) {
            cell = ' ';  // Reset the cell to empty
        }
    }
}

