#include "../headers/player.h"
#include "../headers/board.h"
#include "../headers/config.h"
#include "../headers/game.h"
#include "../headers/menu.h"
#include "../headers/ships.h"
#include <iostream>

Player::Player() : playerHits(0), playerMisses(0) {}

void Player::getMoveFromUser(int& row, int& col, const std::vector<std::vector<char>>& board) const {
    std::string move;

    while (true) {
        // Get the player's move (row and column)
        std::cout << "Enter your move (e.g., A1, F6): ";
        // Check if the input is valid
        if (!(std::cin >> move) || move.size() < 2 || !isalpha(move[0]) || !isdigit(move[1])) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid move in the format 'A1' or 'F6'." << std::endl;
            continue;
        }
        // Convert the column character to uppercase
        char colChar = std::toupper(move[0]);
        // Validate the move
        col = colChar - 'A';  // Convert column character to index (0-based)
        row = std::stoi(move.substr(1)) - 1;

        // Check if the move is out of bounds
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) {
            std::cout << "Invalid move. Cell is out of bounds." << std::endl;
            continue;
        }
        // Check if the cell has already been hit
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            std::cout << "Invalid move. Cell has already been hit. Please try again." << std::endl;
            continue;
        }
        break;  
    }
}

void Player::playerMove(std::vector<std::vector<char>>& board) {
    int row, col;
    displayBoard(board, true);  
    // Ask the user for input or auto-fire
    std::cout << "Do you want to manually input your move (M) or auto-fire (A)? ";
    char choice;
    std::cin >> choice;

    if (std::toupper(choice) == 'M') {
        // Get the player's move from the user
        getMoveFromUser(row, col, board);
    } else if (std::toupper(choice) == 'A') {
        // Auto-fire option
        row = rand() % board.size();
        col = rand() % board[0].size();
        std::cout << "Auto-firing at cell " << static_cast<char>('A' + col) << row + 1 << "..." << std::endl;
    } else {
        std::cout << "Invalid choice. Please enter 'M' for manual input or 'A' for auto-fire." << std::endl;
        return;  
    }
    // Process the valid move (manual or auto)
    if (board[row][col] == 'S') {
        std::cout << "It's a HIT!" << std::endl;
        board[row][col] = 'X';  // Mark the cell as a hit
        playerHits++;
    } else {
        std::cout << "It's a MISS! Target cell contains: " << board[row][col] << std::endl;
        board[row][col] = 'O';  // Mark the cell as a miss
        playerMisses++;
    }
}
