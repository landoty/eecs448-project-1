#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <limits>
#include "board.h"
#include "ship.h"
class Game
{
	private:
    
	
	public:
	Ship** player1_ships;
	Ship** player2_ships;
	Board player1_Board;
	Board player2_Board;
	Board player1_eBoard;
	Board player2_eBoard;
	char hitChar = '*';
	int x, y; 
	int numShips = 0;
    Game();
	void fire(std::string playerName);
	bool gameEndCheck();
	void shipPlacement();
	~Game();
 
};
#endif