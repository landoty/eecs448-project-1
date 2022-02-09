#include "game.h"

Game::Game()
{

}

void Game::shipPlacement()
{
    //when game starts place ships using board and ship class methods
    //let players decide how many ships in the game
    
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

}


