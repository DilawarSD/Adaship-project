#ifndef CONFIG_H
#define CONFIG_H

#include <vector>
#include <string>

// Define a structure to represent boat configurations
struct Boat {
    std::string type;
    int length;

    // Constructor to initialize Boat
    Boat(const std::string& boatType, int boatLength) : type(boatType), length(boatLength) {}
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