#include "../headers/game.h"
#include "../headers/ships.h"
#include "../headers/board.h"
#include "../headers/config.h"
#include "../headers/player.h"
#include "../headers/computer.h"
#include "../headers/menu.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void displaymenu() {
  std::cout << "=== Welcome to Adaship! ===\n";
  std::cout << "1. Player 1 VS Computer!\n";
  std::cout <<"2.Exit\n";
  std::cout << "============================\n";
}

void Menu::executeMenuOption() {
    int choice;
    Config config;

     do {
            displayMenu();
            std::cout << "Enter your choice (1 or 2): ";
            std::cin >> choice;
            // Check if the input is an integer
            if (std::cin.fail()) {
                std::cin.clear();  // Clear the fail state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore remaining characters
            }
            switch (choice) {
                case 1: {
                    // Specify the configuration file
                    std::string configFile = "adaship_config.ini";
                    // Use the static function Config::readConfig
                    config = Config::readConfig(configFile);
                    // Create game instance
                    Game game(config);
                    // Run the existing gameplay logic
                    game.play();

                    break;
                }
                case 2:
                    std::cout << "Exiting the program. Goodbye!\n";
                    break;

                default:
                    std::cout << "Invalid choice. Please enter 1 or 2.\n";
            }
        } while (choice != 2);
    }



