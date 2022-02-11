/** ------------------------------------------------------------------------
 * @file : Board.cpp
 * @author : Duy Vu
 * @assignment : EECS448 - Project 1
 * @brief : Class that defines the game board. Is able to create, print, and update board.
 * @date: 02-07-22
 *
 ------------------------------------------------------------------------ **/

#include "board.h"
#include <iostream>
#include "ship.h"

Board::Board()			
{
	m_boardSize = 10;	//board size is always 10
	board = nullptr;
	board = new char*[m_boardSize];
	for (int i=0; i<m_boardSize; i++)
	{									//2D array is created to represent board
		board[i] = new char[m_boardSize];		//Top left: 0,0		Bottom right: 9, 9	when size is 10
	}
	
	char entry = '-';
	for (int i=0; i<m_boardSize; i++)
	{
		for (int j=0; j<m_boardSize; j++)
		{
			board[i][j] = entry;			//2D array filled with dashes
		}
	}
}

Board::~Board()
{
	for (int i=0; i<m_boardSize; i++)	//2D array of board is deleted
	{
		delete[] board[i];
	}
	delete[] board;
}

void Board::printBoard()
{
	int row = 1;						//row and col are used to print out board coordinates on the side of the board
	char col = 'A';
	std::cout << '\n' << "	";
	for (int i=0; i<m_boardSize; i++)
	{
		std::cout << col << '	';				//Letters A-J are printed at top of board
		col++;
	}
	std::cout << '\n';
	for (int i=0; i<m_boardSize; i++)
	{
		std::cout << row << '	';		//Numbers 0-9 are printed on side of board
		row++;
		for (int j=0; j<m_boardSize; j++)
		{
			std::cout << board[i][j] << '	';		//Actual board is printed out
		}
		std::cout << '\n';
	}
}

void Board::updateBoard(int col, int row, char entry)	//Allows for any coordinate on board to be updated
{
		board[row][col] = entry;					
	
}

void Board::placeShip(Ship* entry)  
{
	int increment = 0;
	int direction = 0;
	int newCol = 0;
	char col = entry->get_horiz_start();
	col = tolower(col);
	newCol = col;
	newCol = col-97;
	int row = entry->get_vert_start();	
	if(entry->get_direction() == 'h')
	{
		direction = newCol;
	}
	if(entry->get_direction() == 'v')
	{
		direction = row;
	}
	if(direction+entry->get_size()-1 < 10)
	{
		for (int i=0; i<entry->get_size(); i++)
		{
			if(isValidSpace(newCol, row-1))
			{
				updateBoard(newCol, row-1, entry->get_ship()[increment]);
				if(entry->get_direction() == 'h')
				{
					newCol++;
				}
				if(entry->get_direction() == 'v')
				{
					row++;
				}
				increment++;
			}
			else
			{
				throw(std::runtime_error("Invalid space."));
			}
		}
	}
}

bool Board::isValidSpace(int col, int row)
{
	if(board[row][col] == '-')		//Checks if coordinate currently has no ships
	{
		return(true);
	}
	else
	{
		return(false);
	}
}


