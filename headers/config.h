#ifndef CONFIG_H
#define CONFIG_H

#include <vector>
#include <string>

// Define a structure to represent boat configurations
struct Boat {
     std::string name;
    int size;
    std::pair<int, int> position;

    // Constructor for Boat
    Boat(const std::string& boatName, int boatSize) : name(boatName), size(boatSize) {}
};

// Define a structure to represent game configuration
class Config {
public:
    int boardSize;
    std::vector<Boat> boats;

    // Function declarations
 static Config readConfig(const std::string& configFile);
    std::vector<std::vector<char>> initializeBoard() const;

// Function to initialize the board based on the configuration
};


#endif 