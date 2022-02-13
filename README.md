# EECS 448 Project 1 - Battleship

## System Overview

We will be implementing Project 1 – Battleship – using C++ in a
command line interface application. Using the object-oriented design
paradigm, we will be implementing a handful of classes for modularity.
These will include the Executive, Game, Board, and Ship classes.

## Interface

- All interfaces should be intuitively built such that the user can determine what to input at each prompt
- Type and value validation are included at each input point such that invalid input will not be accepted, and the user will be handed feedback accordingly
- Lines/blocks signify separation in the game flow that allow for easier reading and tracking of the game status
- Ships can be oriented vertically or horizontally and cannot be moved after being placed
- For the user’s own board, an ‘s’ signifies a ship placement
- For the user’s enemy board, an asterisk signifies a hit on an opponent’s ship and an ‘M’ signifies a missed fire attempt.
- Both the enemy and player’s own board will be printed after each fire
- The game will end once all ships are sunk by either opponent

## Class Descriptions

See full descriptions of each method in the [documentation](https://github.com/landoty/eecs448-project-1/blob/main/documentation/project1_documentation.pdf)

- **Executive** instantiates the Game class and contains a single method to play the Battleship game

- **Game** handles all necessary game logic including placing ships, firing, and checking if the game is completed. This class instantiates both the Board and Ship class to implement the classic Battleship game.

- **Board** handles all necessary operations concerning the game board and is represented by a 10x10 grid with vertical axis (1-10) and horizontal axis (A-J). This includes placing ships, updating hits and misses, and printing. This class is instantiated by the Game class.

- **Ship** contains the necessary values and functionality resembling a single ship. This includes its size, direction, starting coordinates, and hit and sunk status. This class is instantiated by the Game class

## Build System and Running

- A makefile is included that handles all compilation and linkage. An executable **Battleship** is generated to play a game
- Command **make** builds the executable
- Command **make clean** removes the executable and all object files

## Included Libraries
- [iostream, c++ std library](https://www.cplusplus.com/reference/iostream/)
- [string, c++ std library](https://www.cplusplus.com/reference/string/string/)
- [stdexcept, c++ std library](https://www.cplusplus.com/reference/stdexcept/)
