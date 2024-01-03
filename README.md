# ADASHIP project C++

# Challenge Outline 

## A. Summary and Review
This is my project which is called ADASHIP which is based off the game called battleship in C++. The battleship game has several key components that I had face before implementing the functionality. Which are the game board making sure that the board is displayed. Placing the ships onto board either if it is manually or auto-placement. These ships would be different names and sizes such carrier is size 5 and battelship is size 4 in my game. Another thing would be the players themselves as they would need to be interacting with game. Player having their own ships with their own placement on their own board when they go up against the computer. Turn system which is means player or computer take turns when the game starts. The attack option if the computer or player attacks the otehr oppenement they would get know depending on which cell they have attacked it would either be hit or miss depending where they attacked and it is empty it would be a miss and if it has a ship then it would be a hit. Another one was validation so if the board is 10x10 then you say a12 to attack it would be out of bounds and if you already attacked a spot previously and you hit it again it would say that it has already been hit. Winning criteria is that whoever gets rid of all the ships on the opponents board wins. 

## C. Initial Working Plan
My initial working plan at the beginning was to make sure I was able to config my plain text file called adaship_config.ini so it is able to read what I wanted the board size and boats size to be and from there was to create a board that would be able to link with my config so when I want to change the size of the board or boat it will change without me hardcoding it into my board and is just a small update to my plain text file that would change the board and boat size. The strategy that I went with to link these files together was by creating separate files and headers that I would put into the cpp files that would connect the two files and I would run the file through the main.cpp and this was the process that I carried on when I added more files. It helped split the code up and was much easier to maintain and easier to read the code. So after I linked the the board and config file. I then moved on to then implement placing of the ships on the board. This was by again creating a header file and link this to the board and config files as my ship needs access to my boat name and size and the board as I would like the player to be able to place the ships on the board that I created. Also having an option for the player to either manually or automatically. Then the next phase was then adding the player and computer file to be able to access my manual placement ship and automatic ship. Another for player is to be able to manual fire or auto fire on the board to attack the ships on the opponents board and this would be the same as computer. Then the last two was game and menu files. The game file is able to play the game which allows the player and computer to go up against each and having a validation to check winner which is whoever destroys all the ships win. The menu is just to able to have 2 options which are player vs computer and exit which exits you out of the game completely. 

## D. Analysis and Decomposition 
For the board generation it was important to make sure that I got the coloumn and rows to be aligned and so when the user(player) wants to place the ships or attack the ships and the player types the coloumn and row it would go to the right cell that was called. For configuration I wanted to make sure that it is able to able read the board and boats for an example on the plain text it configures from if the board is 10x10 the board without any hardcoding for the 10x10 it would display the board as 10x10 and if I did change the size to 20x20 on the plain text file (adaship_config.ini) the board will automatically change to that size same as the boat size aswell. For the ship placement it was important to make sure that the manual placement was able to go to the right row and coloumn the player would want to put them and with the auto placement is to be place them randomly on the board and also allowing the player to see the ships before carrying on the game if they are ok with the ship placement. For the player is important to be able to place the ships, its also attacking the opponents board with again with accurate placing on where the player wants to attack for an example if the player wants to attack A1 it should attack there, this will be the same for computer with creating their own board and attacking the other board. For the game is making sure to validate the winner which is whoever destroys all of the ships win for an example if player destroys all of computer ships, player is the winner. 

## E. Object-Oriented Design 
For object-oriented idea was to create classes for each component such as class player which will be available to be across all the files so files like game and ship are able to access it. Another design idea that I implemented was a stuct for boats which will be the boats name and sizes that can be reused in the other files for an example ships so the user knows what ship was placed and the size of the ship that was placed on the board for an example carrier is size 5. I used classes which is encapsulation state are stored privately within the specified class for an example I created class player. Another object-oriented idea I was with the classes that I used was inheritance so as I mentioned before class player being able to reuse that across the file without repeating the full code again where I would need to use it for an example I was using class player in the game.cpp file. Abstraction was used such as for boats I create a struct where it has the boat size and boat name within the stuct that can be used for an example boats name and boats size in the ship file in a similar way to inheritance. 

# Development
## A. Adoption and use of 'good' standards
There were different standards that were followed and implemented when working on this project. These are the following coding standards I followed:

1. I made sure to use names that were easy to understand when naming my functions and classes used in my project.
2. Use of camelCase and Pascal case in my project which is for consistent purpose in my project.
3. Comments were used to help understand the code that was written incase the code might be confusing to understand and not easy to read
4. Breaking up the code to have small functions and not large functions.

Another good standard I used was verion control when using github when pushing my code which were:

1. Commits messages that were pushed to make sure they were clear and understandable.
2. During my time working on this project I used branches at the beginning to help with any issues that might occur such as bugs issues that I didn't want to affect the main branch.

## Phase 1 developement
Added plain text file that contains the board size and boats. Created classes and struct for the config file and and had a basic function for the board. Encapsulation was used as mention before with the classes for the config and abstraction used with struct boat as I had mentioned about the boat name and boat sizes. There were changes here when I was creating these files for an example the headers file at first were not working so I had to restart again and get a better understanding of how to create the two headers for board and config to be able to link and allow the board to have access to the config file. 

## Phase 2 developement 
In phase 2 I added the ship implementation of being able to place the ships either manually and also auto-placement to give the option to the player which they would like but also for the computer to be able to have access to auto-placement as the battleship game is to take turns and destroy each other ships. Validation of the ships aswell for an example if you place a ship where you already have placed a ship and if the user wrote format for an example if its 5a it is the wrong and it should be A5. Being able to have classes allows good object-oriented ideas to come through such epcasulation and inheritance during this process to make the code alot more resuable. 

## Phase 3 developement 
In phase 3 was the implemention of player and computer files being introduced into the project. These two files were implemented to allow player or computer to be able to fire onto to the board and be able to either get a hit if they end up hitting the board or miss if the ended up hitting an empty cell. Again being robust by preventing invalid hits that were out of bounds of if they have already hit the cell before. 

## Phase 4 developement 
In phase 4 was now the implementation of the game. Which were making sure the player and computer were taking turns. Being able to place their own ships on they own boards. Then finally being able to see who wins or loses which the conditions being meant and then ending with the notifications of who won the game and was also the implementation of the menu file which is where the user was either pick player vs computer or to exit the program. 

## Ensuring quality through testing and resolving
The testing strategy that was used was manual testing which when I implemented a function I would run the program to see if it was able to run fine or if an issue would appear. For an example implementating validations of hit and miss making sure that it when its able to hit your entire board. Ship placement making sure its valid. Regression testing also as when doing auto fire and auto placement that each time it was random and not following the same pattern each time I would run the program.

## Bug Issues
One bug issue that I and resolve was when the player needs to hit the computers board that is placed in the 10th row. The bug issue that would occur was that when I would want to hit a cell that was in the 10th row and wrote A10 or B10 it wouldn't recognise the row and would display an 'X' for hit or 'O' for miss. When looking back at the code at the code I realised that it wouldn't recognise it because the code would think that 9th row was the last one on the board. So I corrected this by making sure that the code would read the board size to where it could recognise the board size properly without the rows being cut out limiting board by either being before the last row or pass it. This was a good techinque that I took as I identify this right away with regression testing as soon as I implemented and manually checked each row and coloumn to make sure it works properly. 

## Reflection on key designs challenges 
One challange that I faced was making sure the boards are seperate for player and computer. As at first when implementing this I had both computer and player ships on the same board which it shouldn't. The solution for this was was giving computer access to board but having a seperate for name compared to the player board for an example computer would be computerBoard while player would be playerBoard. 

Another challenge I had was avoiding code dupilcation such as for player to be used in the game file not repeating all the but being to get access to use due to encapsulated on the class and using inheritance to reuse the code to help keep good coding standard and maintain readability. 

# Evaluation 

## Analysis
For code refactoring I had to split my code for my player.cpp file as I only had one functon which is called playerMove and that had contained if the user would like to make a move on the board and also if they would want to manually fire or auto fire the opponents board. So I decided to split that into two functions to keep the code maintained and easier to understand. Here is the code below which is after I have refactored the code. 

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

I also used code reusability as well with the player function as I needed to use this functionality in my game file. This is the code I used for reusability. 

void Game::playerMove(std::vector<std::vector<char>> &board) {
  Player player; 
  player.playerMove(
      board); 
}

This allows me use my player class function from my player.cpp without me duplicating the code. 

For code smelling one example that I had was in my boat struct I had code that wasn't used in when creating my program. This was then commented out and later on removed as I have mentioned that this code was never used. 

struct Boat {
  std::string name;
  int size;
  //std::pair<int, int> position;

  Boat(const std::string &boatName, int boatSize)
      : name(boatName), size(boatSize) {}
};
The code that is commented which is about teh position was never used and was removed from my code as it wasn't used. 

## Implementation and effective use of advanced programming principles
One principle idea I used was inheritance this helps to make sure that you are able to reuse code without any duplication of the code. For an example for both computer and player files I was able to use them in my game.cpp file without duplicating code for me to use them to allow both player and computer play the ADAship game. Here is how I reused the code from player and computer.cpp file. 

void Game::playerMove(std::vector<std::vector<char>> &board) {
  Player player; 
  player.playerMove(
      board); 
}

void Game::computerMove(std::vector<std::vector<char>> &board) {
  Computer computer;
  computer.computerMove(board);
}
This allows me to have access to the computer and player code files without any sorts of duplication and keeps the code easier to maintain and is structured well. 

Another principle idea used is abstraction in my boat struct which is in my config.h file. This allows me to able to use the boat name and sizes. 

struct Boat {
  std::string name;
  int size;

  Boat(const std::string &boatName, int boatSize)
      : name(boatName), size(boatSize) {}
};
This struct boat is very efficient as this abstraction allows me to use all the relevant data about the boat which reduces complexity within the code. 

For encapsulation I have used this a lot in my project as I have a lot of classes that demostrate this I will show you one example of my code where I have used this in my ships.h file. 

class Ships {
public:
Ships() : shipsPlaced(false) {}

static bool isValidPlacement(int startRow, int startCol, int size, bool isHorizontal, const std::vector<std::vector<char>>& board);

void autoPlaceShip(const Boat& boat, const Config& config, std::vector<std::vector<char>>& board);

void manualPlaceShip(const Boat& boat, const Config& config, std::vector<std::vector<char>>& board);

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
bool shipsPlaced;  
bool isPlayer;
};

Here I have demostrated encapsulation as within this class I have shown private member functions which means they can only be accessed or modified by the member functions of the class. Public member provides an interface for interacting with the class and allows manipulation and retrieval of the class's internal state. The states used for an example shipsplaced manages the states of the ships being placed and isplayer represents the player.  All of these variables are accessed through member function. 

## Features showcase and embedded innovations
I want to show my showcase on my computer.cpp function to show how I was able to implement the computer to be able to make randomise moves that doesn't have a pattern during the game battleship experience. 

Computer::Computer() { std::srand(std::time(0)); }

void Computer::computerMove(std::vector<std::vector<char>> &board) {
  // Seed for random number generation
  int row, col;
  // Generate random moves without checking validity
  row = std::rand() % board.size();
  col = std::rand() % board[0].size();
  // Process the move
  if (board[row][col] == 'S') {
    std::cout << "Computer hit your ship!" << std::endl;
    computerHits++;
    board[row][col] = 'X'; 
  } else {
    std::cout << "Computer missed." << std::endl;
    computerMisses++;
    board[row][col] = 'O'; 
  }
}

The features the computer make unpredicted moves with 'std::rand()' and helps to keep the gaming experience engagaing. The hit and miss feedback features makes a move on the player board when attacking their ships if the computer hits the players ship the response will be computer hit your ship, while if they ended up not hitting the opponents the ship it will be computer missed. 

The good the randomise feature is the engaging player experience as for the player it will keep them engaged as they wouldn't know what computer move will be, this would result in replayability as each time the user(player) plays the game it will feel fresh and new as the computer attacking the board will always be different. 

Another one I would like to showcase is my game.cpp file to show how I implemented the game to work with the player and computer taking turns.

Game::Game(const Config &config) : config(config) { std::srand(std::time(0)); }

std::vector<std::vector<char>> Game::initializeBoard() const {
  return config.initializeBoard();
}

// Player move function with improved error handling
void Game::playerMove(std::vector<std::vector<char>> &board) {
  Player player; // Create an instance of the Player class
  player.playerMove(
      board); // Delegate to the playerMove function in the Player class
}

void Game::computerMove(std::vector<std::vector<char>> &board) {
  Computer computer;
  computer.computerMove(board);
}

bool Game::checkWin(const std::vector<std::vector<char>> &board) const {
  for (const auto &row : board) {
    for (char cell : row) {
      if (cell == 'S') {
        return false; 
      }
    }
  }
  return true; 
}

void Game::placeShips(std::vector<Boat> &boats, Ships &playerShips,
                      Ships &computerShips, const Config &config) {
  // Place ships manually
  playerShips.manualPlaceAllShips(boats, config, playerBoard);
  displayBoard(playerBoard,false);

  for (const auto &boat : boats) {
    computerShips.autoPlaceShip(boat, config, computerBoard);
  }
}

void Game::play() {
  playerBoard = initializeBoard();
  computerBoard = initializeBoard();
  Ships playerShips(true); 
  Ships computerShips(false);
  // Get the list of boats from the configuration
  std::vector<Boat> boats = config.getBoats();
  // Place ships
  placeShips(boats, playerShips, computerShips, config);
  // Player vs Computer gameplay
  while (true) {
    // Player's turn
    std::cout << "Player's turn:" << std::endl;
    displayBoard(playerBoard,false); // Use player's board
    playerMove(computerBoard); // Pass computer's board to playerMove
    // Check if the player has won
    if (checkWin(computerBoard)) {
      displayBoard(
          computerBoard,true); // Display the final state of the computer's board
      std::cout << "Congratulations! You win!" << std::endl;
      break;
    }
    // Computer's turn
    std::cout << "Computer's turn:" << std::endl;
    displayBoard(computerBoard,false); // Use computer's board for display
    computerMove(playerBoard);   // Pass player's board to computerMove
    // Check if the computer has won
    if (checkWin(playerBoard)) {
      displayBoard(
          playerBoard,false); // Display the final state of the player's board
      std::cout << "Computer wins! Better luck next time." << std::endl;
      break;
    }
  }
}

The game is able to initialize the board dynamically based on my config class that I created. This allows flexible game setup with various configurations to allow adaptability of the game for an example if I want to change the board from 10x10 to 20x20 or 8x8 it will be able to make that change. 

The player interaction allowing the player to place the ships on the board during the placement phase. This will enhance player experience with engagement and strategy and decision making which will make more interactive and immersive gameplay. 

The same will go for computer however this will be different allowing them to make unpredictable move on the board. Which will keep them players engaged and replayability aspect aswell. 

The win condition will check the game win condition after each players move. The feature ensures the game is competitive with clear outcomes of who wins the game after each session. 

The game.cpp file uses the classes of game,player,computer and ships which demostrates an object-oriented design. Which helps promote code organisation, encapsulation and reusability. 

The game is able to use the config class with easy adjustment without changing the code logic and with no hardcoding involved in creating the board and boats. 

The game loop being continous to keep the flow of the game going without it breaking. This will allow smooth transition between player and computer turn. 

This game file will allow a combination of dynamic initialsation, ship placement and gameplay that will allow the players to enjoy the experience of the game. This also allows win condition add strategic depth to the game as the players need to think about the their moves of where the ships are placed and also hitting the computers ship. Finally the adaptablilty of the config class having wide range of preferences for an example changing the board size, boat size and name in the adaship_config.ini text file. 

## Improved algorithms 


## Reflective Review
Overall my review on my project as a whole was a good experience to be able to structure my code understanding of good planning and using object-oriented ideas. However at the beginning of the project I did struggle to connect the files to work with each other but that was quickly resolved as I created a new replit and started from scratch and made sure to take my time in making sure that the headers file were done right and connecting the files to each other. The important thing I would take on to continue my growth as a programmer is taking all the things I spoke about which were structing of code, before starting having a good plan and set task to complete and another part is making sure to not have large functions but break them down into smaller functions. 

What I would do in the future developement phases as this is version 1, for version 2 I would implement player vs player 2 so this will be different to how player vs computer would work as this would have two users having access to their own boards and being able manually place the ships and also hit each others boards either manually or auto fire, which would help engage the players experience and replayability due to the two users playing each other having to strategy and plan their moves. 