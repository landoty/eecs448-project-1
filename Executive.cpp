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
 #include <stdexcept>
 #include <iostream>
 
 Executive::Executive()
 {
	 gameOver = false;
	 boardSize = 10;
	 shipNumber = 0;
 }
 
 Executive::play()
 {
	 std::cout<<"Welcome to Battleship!\n";
//	 std::cin>>boardSize;
//creates a board object to make the game board and then displays it
	 board gameBoard1;
	 board gameBoard2;
	 gameBoard1.createBoard(boardSize);
	 gameBoard2.createBoard(boardSize);
	 gameBoard1.printBoard();
	 std::cout<<"How many ships will each player get? (1-5)\n";
	 std::cin>>shipNumber;
	 //player 1 places ships
	 std::cout<<"Player 1, place your ships.\n";
	 try
	 {
		for(int i = 1; i<=shipNumber; i++)
		{
			Ship battleshipShip(i);
			std::cout<<"Where should your size "<<i<<" ship go? Enter x and y coordinates.\n";
			gameBoard1.placeShip(battleshipShip);
		}
	 }
	 catch(std::exception& e)
	 {
		 std::cout<<e.what();
	 }
	 //player 2 places ships
	 std::cout<<"Player 2, place your ships.\n";
	 for(int i = 1; i<=shipNumber; i++)
	 {
		 Ship battleshipShip(i);
		 std::cout<<"Where should your size "<<i<<" ship go? Enter x and y coordinates.\n";
		 gameBoard2.placeShip(battleshipShip);
	 }
	 //starts game by looping until game over is true
	 do
	 {
		 //asks player one for a move
		 //then asks player two for a move
	 }while(gameOver == false);
	 std::cout<<"Game over!\n";
 }