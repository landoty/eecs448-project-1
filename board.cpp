#include "Board.h"

Board::Board()
{
	m_boardSize = 10;
	board = nullptr;
	for (int i=0; i<m_boardSize; i++)
	{
		
	}
}

void Board::createBoard(int size)
{
	board = new char*[size];
	for (int i=0; i<size; i++)
	{
		board[i] = new char[size];
	}
	
	char entry = '-';
	for (int i=0; i<m_boardSize; i++)
	{
		for (int j=0; j<m_boardSize; j++)
		{
			board[i][j] = entry;
		}
	}
}

void Board::printBoard()
{
	int row = 0;
	char col = 'A';
	std::cout << "*";
	for (int i=0; i<m_boardSize; i++)
	{
		std::cout << col;
		col++;
	}
	std::cout << '\n';
	for (int i=0; i<m_boardSize; i++)
	{
		std::cout << row;
		row++;
		for (int j=0; j<m_boardSize; j++)
		{
			std::cout << board[i][j];
		}
		std::cout << '\n';
	}
}

void Board::updateBoard(int x, int y, char entry)
{
	board[x][y] = entry;
}