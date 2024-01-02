#include "../headers/ships.h"
#include "../headers/board.h"
#include "../headers/config.h"
#include "../headers/menu.h"
#include <iostream>
#include <limits>
#include <random>
#include <vector>

Ships::Ships(bool isPlayer) : isPlayer(isPlayer) {
  // Initialize other member variables and perform other setup if needed
}

bool Ships::isValidPlacement(int startRow, int startCol, int size, bool isHorizontal, const std::vector<std::vector<char>>& board) {
    // Check if the placement is within the bounds of the board
    if (startRow < 0 || startRow >= board.size() || startCol < 0 || startCol >= board[0].size()) {
        return false;  
    }
    // Check if the ship fits within the board
    if (isHorizontal) {
        if (startCol + size > board[0].size()) {
            return false;  // Ship goes beyond the right edge of the board
        }
    } else {
        if (startRow + size > board.size()) {
            return false;  
        }
    }
    // Check if the placement overlaps with other ships
    for (int i = 0; i < size; ++i) {
        if (isHorizontal) {
            if (board[startRow][startCol + i] != ' ') {
                return false;  
            }
        } else {
            if (board[startRow + i][startCol] != ' ') {
                return false;  
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
            continue;  
        }

        char userInputColumn = toupper(userInput[0]);  
        int userInputRow = userInput[1] - '0';  
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
                board[startRowIndex][startColIndex + i] = 'S';  
            }
            break;  // Exit the loop if placement is valid
        } else if ((orientation == 'V' || orientation == 'v') && isValidPlacement(startRowIndex, startColIndex, size, false, board)) {
            // Update the board for vertical placement
            for (int i = 0; i < size; ++i) {
                board[startRowIndex + i][startColIndex] = 'S';  
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

    char shipSymbol = (isPlayer) ? 'S' : 'S';  
    do {
        startRow = dis(gen);
        startCol = dis(gen);
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
            std::vector<Boat> remainingBoats = boats;  
            // Ask if the user wants to manually place ships
            std::cout << "Do you want to manually place ships? (Select No for autoplacing) (Y/N): ";
            std::cin >> manualPlaceChoice;
            // Validate the input
            while (toupper(manualPlaceChoice) != 'Y' && toupper(manualPlaceChoice) != 'N') {
                std::cout << "Invalid choice. Please enter 'Y' or 'N': ";
                std::cin >> manualPlaceChoice;
            }

            size_t boatIndex = 0;

            while (toupper(manualPlaceChoice) == 'Y' && !remainingBoats.empty()) {
                // Display the list of remaining boats and their sizes
                std::cout << "List of remaining boats:" << std::endl;
                for (const auto& boat : remainingBoats) {
                    std::cout << boat.name << ", " << boat.size << std::endl;
                }

                // Display the name and size of the current boat
                std::cout << "Enter the placement for " << remainingBoats[boatIndex].name << " (size " << remainingBoats[boatIndex].size << "): ";

                if (toupper(manualPlaceChoice) == 'Y') {
                    manualPlaceShip(remainingBoats[boatIndex], config, board);
                    // Remove the placed boat from the list of remaining boats
                    remainingBoats.erase(remainingBoats.begin() + boatIndex);
                    // Display the board after each ship placement
                    displayBoard(board, false);
                } else {
                    autoPlaceShip(remainingBoats[boatIndex], config, board);
                    // Display the board after auto-placement
                    displayBoard(board, false);
                }
                // Ask if the user wants to manually place the next ship
                std::cout << "Do you want to manually place the next ship? (Y/N): ";
                std::cin >> manualPlaceChoice;
                // Validate the input
                while (toupper(manualPlaceChoice) != 'Y' && toupper(manualPlaceChoice) != 'N') {
                    std::cout << "Invalid choice. Please enter 'Y' or 'N': ";
                    std::cin >> manualPlaceChoice;
                }
            }
            // Auto-placement for the remaining ships
            for (const auto& boat : remainingBoats) {
                autoPlaceShip(boat, config, board);
            }
            // Display the board after auto-placement
            displayBoard(board, false);
            // Ask if the user wants to reset the board and replace the ships
            std::cout << "Do you want to reset the board or continue? (R/C): ";
            std::cin >> resetChoice;
            // Validate the input
            while (toupper(resetChoice) != 'R' && toupper(resetChoice) != 'C') {
                std::cout << "Invalid choice. Please enter 'R' or 'C': ";
                std::cin >> resetChoice;
            }
            if (toupper(resetChoice) == 'R') {
                resetShipboard(board);
            }
        } while (toupper(resetChoice) == 'R');
    }
}

bool Ships::isShipPlaced(const Boat& boat, const std::vector<std::vector<char>>& board) {
    int shipSize = boat.size;
    int count = 0;

    for (const auto& row : board) {
        for (const auto& cell : row) {
            if (cell == boat.name[0]) {
                count++;
            }
        }
    }
    return count >= shipSize;  
}

bool Ships::allShipPlaced(const std::vector<Boat>& boats, const std::vector<std::vector<char>>& board) {
    for (const auto& boat : boats) {
        if (!isShipPlaced(boat, board)) {
            return false;  
        }
    }
    return true;  
}

void Ships::resetShipboard(std::vector<std::vector<char>>& board) {
    for (auto& row : board) {
        for (auto& cell : row) {
            cell = ' ';  
        }
    }
}
