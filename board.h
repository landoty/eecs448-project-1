/** ------------------------------------------------------------------------
 * @file : Board.cpp
 * @author : Duy Vu
 * @assignment : EECS448 - Project 1
 * @brief : Class that defines the game board. Is able to create, print, and update board.
 * @date: 02-07-22
 *
 ------------------------------------------------------------------------ **/

#ifndef BOARD_H
#define BOARD_H
#include "ship.h"

class Board
{
	private:
	int m_boardSize;
	char** board;
	
	public:
	
	/**
       * @pre : None
       * @post : m_boardSize set to 10 and ptr set to null
       * @param : None
       * @throw : None
       * @return : None
    **/
	Board();
	
	/**
       * @pre : Board array exists
       * @post : deletes 2D array
       * @param : None
       * @throw : None
       * @return : None
    **/
	~Board();
	
	/**
       * @pre : None
       * @post : Prints out contents of board 2D array
       * @param : None
       * @throw : None
       * @return : None
    **/
	void printBoard();
	
	/**
       * @pre : None
       * @post : Changes element of board array at the parameter coordinates
       * @param : Takes in coordinates and entry
       * @throw : None
       * @return : None
    **/
	void updateBoard(char col, int row, char entry);
	
	/**
       * @pre : None
       * @post : Board is updated with placement of ship at coordinates
       * @param : None
       * @throw : Throws error if coordinates out of bounds, or ship already exists, or if direction invalid
       * @return : None
    **/
	void placeShip(Ship* entry);
	
	/**
       * @pre : None
       * @post : None
       * @param : None
       * @throw : none
       * @return : True if coordinate in board array has no ship, false otherwise
    **/
	bool isValidSpace(int col, int row);
};
#endif