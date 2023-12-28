#ifndef SHIPS_H
#define SHIPS_H

#include "config.h"
#include <vector>

class Ships {
public:
    static void manualPlaceShip(const Boat& boat, const Config& config, std::vector<std::vector<char>>& board);
    static void autoPlaceShip(const Boat& boat, const Config& config, std::vector<std::vector<char>>& board);
    static bool isValidPlacement(int startRow, int startCol, int size, bool isHorizontal, const std::vector<std::vector<char>>& board);

private:
bool isPlayer;
};

#endif 