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
   
    return false;

}
Game::~Game()
{
    
}


