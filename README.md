# ADASHIP project C++

## Challenge Outline 
This is my project which is called ADASHIP which is based off the game called battleship in C++. The battleship game has several key components that I had face before implementing the functionality. Which are the game board making sure that the board is displayed. Placing the ships onto board either if it is manually or auto-placement. These ships would be different names and sizes such carrier is size 5 and battelship is size 4 in my game. Another thing would be the players themselves as they would need to be interacting with game. Player having their own ships with their own placement on their own board when they go up against the computer. Turn system which is means player or computer take turns when the game starts. The attack option if the computer or player attacks the otehr oppenement they would get know depending on which cell they have attacked it would either be hit or miss depending where they attacked and it is empty it would be a miss and if it has a ship then it would be a hit. Another one was validation so if the board is 10x10 then you say a12 to attack it would be out of bounds and if you already attacked a spot previously and you hit it again it would say that it has already been hit. Winning criteria is that whoever gets rid of all the ships on the opponents board wins. 

Class Diagram:

Player
---------------------
- name: string
- ships: Ship
- turn: bool
---------------------
+ autoPlacement
+ manualPlacement

Ship
---------------------
- name: string
- size: int
---------------------

Board (config)
---------------------
- grid: 10x10
---------------------

WinningResult
---------------------
- results: bool hits all 
-----------------------



## Development

## Evaluation 