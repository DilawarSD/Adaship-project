#ifndef SHIPS_H
#define SHIPS_H

#include "config.h"
#include <vector>
#include <iostream>
#include <random>
#include <algorithm>

class Ships {
public:
Ships() : shipsPlaced(false) {}
    static void manualPlaceShip(const Boat& boat, const Config& config, std::vector<std::vector<char>>& board);

    static void autoPlaceShip(const Boat& boat, const Config& config, std::vector<std::vector<char>>& board);

    static bool isValidPlacement(int startRow, int startCol, int size, bool isHorizontal, const std::vector<std::vector<char>>& board);

void manualPlaceAllShips(const std::vector<Boat>& boats, const Config& config, std::vector<std::vector<char>>& board);

void autoPlaceRemainingShips(const std::vector<Boat>& boats, const Config& config, std::vector<std::vector<char>>& board);

static bool isShipPlaced(const Boat& boat, const std::vector<std::vector<char>>& board);

static bool allShipPlaced(const std::vector<Boat>& boats, const std::vector<std::vector<char>>& board);

static void resetShipboard(std::vector<std::vector<char>>& board);

Ships(bool isPlayer);

bool areAllShipsPlaced() const {
    return shipsPlaced;
}


private:
bool isPlayer;
bool shipsPlaced; 
};

#endif 