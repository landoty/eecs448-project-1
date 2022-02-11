#include "game.h"
#include "ship.h"
#include "board.h"

Game::Game()
{

}

void Game::shipPlacement()
{	
	std::cout << "Enter a number of ships from 1 to 5: ";
	std::cin >> numShips;
	
	player1_ships = new Ship*[numShips];
	player2_ships = new Ship*[numShips];
	
	for (int i=1; i<3; i++)
	{
		for (int j=0; j<numShips; j++)
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
		}
	}
}
void Game::fire(std::string playerName)
{
    
    while((std::cout << "Player: " << playerName << "\nEnter Coordinate to Attack: \n") && (!(std::cin >> x>>y)|| x<=-1 || x>=10 ||y<=-1||y>=10 ))
    {
    std::cout << "Did not input whole number or number is not between 0-9\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    //check for board if hit or miss with if statements
    
   

}
bool Game::gameEndCheck()
{
    //checks if all ships are sunked, who won the game
    //if someone has won 
    return true;
    //if game has not ended
    return false;

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