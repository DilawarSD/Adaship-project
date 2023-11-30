#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

struct Boat {
    std::string name;
    int size;
};

struct Config {
    int boardSize;
    std::vector<Boat> boats;
};

// Function to read the configuration from the 'adaship_config.ini' file
Config readConfig(const std::string& configFile) {
    Config config;
    std::ifstream file(configFile);

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            size_t pos = line.find(":");
            if (pos != std::string::npos) {
                std::string key = line.substr(0, pos);
                std::string value = line.substr(pos + 1);
                if (key == "Board") {
                    config.boardSize = std::stoi(value);
                } else if (key == "Boat") {
                    size_t boatPos = value.find(",");
                    if (boatPos != std::string::npos) {
                        std::string boatName = value.substr(0, boatPos);
                        int boatSize = std::stoi(value.substr(boatPos + 1));
                        config.boats.push_back({boatName, boatSize});
                    }
                }
            }
        }
        file.close();
    } else {
        std::cerr << "Unable to open configuration file: " << configFile << std::endl;
    }

    return config;
}

// Function to initialize the board based on the configuration
std::vector<std::vector<char>> initializeBoard(const Config& config) {
    return std::vector<std::vector<char>>(config.boardSize, std::vector<char>(config.boardSize, ' '));
}

// Function to display the board
// Function to display the board with letters for columns and a simplified grid
// Function to display the board with letters for columns and both vertical and horizontal grid lines
/*void displayBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "   ";
    for (int i = 0; i < board.size(); ++i) {
        char colLabel = 'A' + i;
        std::cout << colLabel << ' ';
    }
    std::cout << "\n";

    for (int i = 0; i < board.size(); ++i) {
        std::cout << i << "| ";
        for (int j = 0; j < board[i].size(); ++j) {
            std::cout << board[i][j] << ' ';
        }
        std::cout << "|\n";
    }
}*/

void displayBoard(const std::vector<std::vector<char>>& board) {
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
            std::cout << " " << board[i][j] << "| ";
        }
        std::cout << "\n";
    }

    std::cout << "-";
    for (int i = 0; i < board.size(); ++i) {
        std::cout << "----";
    }
    std::cout << "\n";
}


int board_main() {
    // Specify the path to the configuration file
    std::string configFile = "adaship_config.ini";

    // Read the configuration from the file
    Config config = readConfig(configFile);

    // Display configuration information for debugging
    std::cout << "Board Size: " << config.boardSize << std::endl;
    for (const auto& boat : config.boats) {
        std::cout << "Boat: " << boat.name << ", Size: " << boat.size << std::endl;
    }

    // Initialize the board based on the configuration
    std::vector<std::vector<char>> board = initializeBoard(config);

    // Display the initialized board
    displayBoard(board);

    return 0;
}


