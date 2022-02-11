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
		std::cout << "Enter a number of ships from 1 to 5: ";
		std::cin >> numShips;
		if(numShips >5 || numShips < 1)
		{
			std::cout << "Invalid number of ships. Try again.\n";
		}
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
					int row = 0;
					char direction = 'a';
					std::cout << "Player "<< i <<", where would you like to place ship " << j+1 << "?\n";
					std::cout << "Column: ";
					std::cin >> col;
					std::cout << "Row: ";
					std::cin >> row;
					std::cout << "Direction: ";
					std::cin >> direction;	
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
    std::cout << "Player: " << playerName << "\nEnter Coordinate to Attack(letters a-j for column and 0-9 for rows (example column: a and 2 )): \n";

    do
    {
    std::cout << "\nColumn: ";
    std::cin >> col;
    col=tolower(col);
    newCol = col;
    newCol = newCol - 97;
    result =(newCol<=9 && newCol >=0);
    if(result == false)
    {
        std::cout << "\nInvalid input. Please enter letters a-j.";
    }
    } while (result == false);  //only accept user input a-j
     
    do
    {
    std::cout << "\nRow: ";
    std::cin >> row;
    result =(row<=9 && row >=0);
    if(result == false)
    {
          std::cout << "\nInvalid input. Please enter numbers 0-9.";
    }
    } while (result == false); //only accept user input 0-9
    
    
   if(myBoard.isValidSpace(newCol,row) == true)
    {
    myBoard.updateBoard(newCol,row,missChar);  //if board space does not have any ships mark with M
    // myShip.hit(newCol,row); //update with ship hit method
    }
    else if(myBoard.isValidSpace(newCol,row) == false)
    {
        myBoard.updateBoard(newCol,row,hitChar); //if board space has a ship mark with *
                                                //update with ship hit method
    }
    myBoard.printBoard(); //print out updated board
}
bool Game::gameEndCheck()
{
    //checks if all ships are sunked, who won the game
    //if someone has won (check all ship classes to see if all has status sunked)
    
    return true;
    //if game has not ended (check all ship classes to see if all has status sunked)
   
    return false;*/

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