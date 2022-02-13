/**------------------------------------------------------------------------
 * @file : game.cpp
 * @author : Eric Zhuo
 * @assignment : EECS448 - Project 1
 * @brief : Game classes that uses methods from board ship and game
 *          header files to implement methods to use for the Battleship game
 * @date: 02-10-21
 *
 ------------------------------------------------------------------------ **/
#include "game.h"
#include "ship.h"
#include "board.h"

Game::Game()
{

}

void Game::shipPlacement()
{

	while(numShips > 5 || numShips < 1)
	{
		std::cout << "===============================================\n";
		std::cout << "Enter a number of ships from 1 to 5: ";
		std::cin >> numShips;
		if(numShips >5 || numShips < 1)
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Invalid number of ships. Try again.\n";
			std::cin >> numShips;
		}
		std::cout << "===============================================\n";
	}

	player1_ships = new Ship*[numShips];
	player2_ships = new Ship*[numShips];

	for (int i=1; i<3; i++)
	{
		for (int j=0; j<numShips; j++)
		{
			int invalid = 1;
			while(invalid != 0)
			{
				try
				{
					char col = 'A';
					int newCol = 0;
					int row = 0;
					char direction = 'a';
					std::cout << "===============================================\n";
					std::cout << "Player "<< i <<", where would you like to place ship " << j+1 << "?\n";
          do
          {
	          std::cout << "Column: ";
	          std::cin >> col;
	          col=tolower(col);
	          newCol = col;
	          newCol = newCol - 97;
	          result =(newCol<=9 && newCol >=0);
	          if(result == false)
	          {
	          	std::cout << "Invalid input. Please enter letters a-j.";
	          }
          }
					while (result == false);

					do
          {
          	std::cout << "Row: ";
						std::cin >> row;
           	result =(row<=10 && row >=1);
           	if(result == false)
          	{
          		std::cout << "Invalid input. Please enter numbers 1-10.";
          	}
          }
					while (result == false);

          do
          {
          	std::cout << "Direction: ";
						std::cin >> direction;
          	result = (direction == 'v' || direction == 'h');
          	if(result == false)
          	{
              std::cout << "Invalid input. please enter v(ertical) or h(orizonal)";
          	}
          }
					while (result == false);
					std::cout << "===============================================\n";

					if(i==1)
					{
						player1_ships[j] = new Ship(j+1, direction, col, row);
						player1_Board.placeShip(player1_ships[j]);
					}
					if(i==2)
					{
						player2_ships[j] = new Ship(j+1, direction, col, row);
						player2_Board.placeShip(player2_ships[j]);
					}
					invalid = 0;
				}
				catch(std::exception& e)
				{
					std::cout << e.what() << '\n';
					invalid++;
				}
			}
		}
	}
}
void Game::fire(std::string playerName)
{
    //checks user input
    char col = 'A';
    int newCol =0;
    int row = 0;
    int missCount =0;
		std::cout << "===============================================\n";
    std::cout << "Player: " << playerName << "\nEnter Coordinate to Attack\n(letters a-j for column and 0-9 for rows\n(example column: a and row: 2 = a2)):\n";
		std::cout << "===============================================\n";
    do
    {
    	std::cout << "Column: ";
    	std::cin >> col;
    	col=tolower(col);
    	newCol = col;
    	newCol = newCol - 97;
    	result =(newCol<=9 && newCol >=0);
    	if(result == false)
    	{
      	std::cout << "Invalid input. Please enter letters a-j.";
    	}
    }
		while (result == false);  //only accept user input a-j

    do
    {
	    std::cout << "Row: ";
	    std::cin >> row;
	    result =(row<=10 && row >=1);
	    if(result == false)
	    {
	          std::cout << "Invalid input. Please enter numbers 1-10.";
	    }
    }
		while (result == false); //only accept user input 1-10

		if(playerName=="Player 1")
    {
    	missCount=0;
			for(int i=0;i<numShips;i++)
 			{
    		try
    		{
      		player2_ships[i]->hit(col, row);
    		}
    		catch(const std::exception& e)
    		{
	        missCount++;
    		}
			}
    	if(numShips==missCount)
    	{
      	player1_eBoard.updateBoard(col,row,missChar);
    	}
		else
    	{
      	player1_eBoard.updateBoard(col,row,hitChar);
    	}

			std::cout << "===============================================\n";
    	std::cout << "Player 1's board\n" ;
    	player1_Board.printBoard();
    	std::cout << "\nEnemy's Board\n" ;
    	player1_eBoard.printBoard();
			std::cout << "===============================================\n";
    }

		if(playerName=="Player 2")
    {
	    missCount= 0;
			for(int i=0;i<numShips;i++)
    	{
	    	try
	    	{
	       player1_ships[i]->hit(col, row);
	    	}
	    	catch(const std::exception& e)
	    	{
	        missCount++;
	    	}
			}
		if(numShips==missCount)
	    {
	      player2_eBoard.updateBoard(col,row,missChar);
	    }
	    else
	    {
	      player2_eBoard.updateBoard(col,row,hitChar);
	    }
			std::cout << "===============================================\n";
			std::cout << "Player 2's board\n";
	    player2_Board.printBoard();
	    std::cout << "Enemy's Board\n" ;
	    player2_eBoard.printBoard();
			std::cout << "===============================================\n";
  	}
}
bool Game::player1Won()
{
    for(int i=0;i<numShips;i++)
    {
        if(player1_ships[i]->is_sunk()==true)
            {
                player1WonCheck = false;
            }
            else
            {
                player1WonCheck = true;
            }
    }
    return player1WonCheck;
}

bool Game::gameEndCheck()
{
		bool player1_end = true;
		bool player2_end = true;
    for(int i=0;i<numShips;i++)
    {
        if(player1_ships[i]->is_sunk() == false)
        {
            player1_end = false;
						break;
        }
		}
		for(int i=0;i<numShips;i++)
		{
			if(player2_ships[i]->is_sunk()==false)
      {
          player2_end = false;
					break;
      }
		}
 	return(player1_end || player2_end);
}
Game::~Game()
{
  	for (int i=0; i<numShips; i++)
	{
		delete player1_ships[i];
		delete player2_ships[i];
	}
	delete[] player1_ships;
	delete[] player2_ships;

}
