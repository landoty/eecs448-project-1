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
	Board myBoard;
	char hitChar = '*';
	char missChar= 'M';
    Game();
	
	bool result;
	void fire(std::string playerName);
	bool gameEndCheck();
	void shipPlacement();
	~Game();
 
};
#endif