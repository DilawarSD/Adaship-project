#include "../headers/config.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

Config Config::readConfig(const std::string &configFile) {
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
            config.boats.push_back(Boat(boatName, boatSize));
          }
        }
      }
    }
    file.close();
  } else {
    std::cerr << "Unable to open configuration file: " << configFile
              << std::endl;
  }

  return config;
}

std::vector<std::vector<char>> Config::initializeBoard() const {
  return std::vector<std::vector<char>>(boardSize,
                                        std::vector<char>(boardSize, ' '));
}
