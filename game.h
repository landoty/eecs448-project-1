/**------------------------------------------------------------------------
 * @file : game.h
 * @author : Eric Zhuo
 * @assignment : EECS448 - Project 1
 * @brief : Header file that defines all variables and methods for 
 * 			game classes to use
 * @date: 02-10-21
 *
 ------------------------------------------------------------------------ **/
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
	char missChar= 'M';
	int numShips = 0;
    Game();
	
	bool result;
	    /**
       * @pre : None
       * @post :  take in playername string to determine what position the ship is and mark with * if not mark M for miss
       * @param : string playerName 
       * @throw : none
       * @retun : N/A
    **/
	void fire(std::string playerName);
		    /**
       * @pre : None
       * @post :  check for ship index and see if status is all sunk, if true then end game else continue
       * @param : none 
       * @throw : none
       * @retun : N/A
    **/
	bool gameEndCheck();
		/**
       * @pre : None
       * @post :  Determine how many ships are in the and allow the player to place the ships alternating between players. 
       * @param : none
       * @throw : none
       * @retun : N/A
    **/
	void shipPlacement();
	~Game();
 
};
#endif