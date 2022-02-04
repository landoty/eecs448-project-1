#ifndef BOARD_H
#define BOARD_H

class Board
{
	private:
	int m_boardSize;
	char** board;
	
	public:
	Board();
	void createBoard(int size);
	void printBoard();
	void updateBoard(int x, int y);
};
#endif