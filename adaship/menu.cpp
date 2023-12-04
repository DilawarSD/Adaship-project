#include <iostream> 

void displaymenu() {
  std::cout << "=== Welcome to Adaship! ===\n";
  std::cout << "1. Player 1 VS Computer!\n";
  std::cout <<"2.Rules\n";
  std::cout <<"3.Exit\n";
  std::cout <<"Enter your choice: " << std::endl;
}

int menu_main() {
  int choice;
    do {
      displaymenu();
     std::cin >> choice;

     switch(choice) {
       case 1:
        std::cout << "Player 1 VS Computer!\n";
       break;
       case 2:
        std::cout << "Rules\n";
       break;
       case 3:
        std::cout << "Exiting...\n";
       break;
       default:
        std::cout << "Invalid choice. Please try again.\n";
     }
      
    } while (choice != 3);
  
    return 0;
}



