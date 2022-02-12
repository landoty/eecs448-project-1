/** ------------------------------------------------------------------------
 * @file : Executive.cpp
 * @author : Aidan Bowen
 * @assignment : EECS448 - Project 1
 * @brief : Class that runs the game and uses methods implemented by other
			classes to control the functions of the game
 * @date: 02-06-21
 *
 ------------------------------------------------------------------------ **/
 #include "Executive.h"
 #include "board.h"
 #include "ship.h"
 #include "game.h"
 #include <stdexcept>
 #include <iostream>
 
 Executive::Executive()
 {
 }
 
 void Executive::play()
 {
	 Game gameFunction;               //initializes the game logic object
	 std::cout<<"Welcome to Battleship!\n";
	 Board gameBoardMoves1;
	 Board gameBoardMoves2;          //4 game boards for view and ships
	 Board gameBoardShips1;
	Board gameBoardShips2;
	 std::string player1 = "Player 1";
	 std::string player2 = "Player 2";
	 gameFunction.shipPlacement();
	 //starts game by looping until game over is true
	 do
	 {
		 //asks player one for a move
		// gameBoardMoves1.printBoard();
		// gameBoardShips1.printBoard();
		 gameFunction.fire(player1);
		 //then asks player two for a move
		// gameBoardMoves2.printBoard();
		// gameBoardShips2.printBoard();
		 gameFunction.fire(player2);
	 }while(gameFunction.gameEndCheck() == false);   //checks if game is over and ends the loop if true
	 if(gameFunction.player1Won()==true)
	 {
		 std::cout<<"\nGame over!\n";
		 std::cout << "Player2 has won!\n";
	 }
	 	else 
	 {
		 std::cout<<"\nGame over!\n";
		 std::cout << "Player1 has won!\n";
	 }
	 
 }
 
 Executive::~Executive()
 {
 }