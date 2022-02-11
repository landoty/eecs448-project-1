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
	 game gameFunction;
	 std::cout<<"Welcome to Battleship!\n";
//	 std::cin>>boardSize;
//	 creates a board object to make the game board and then displays it
	 board gameBoardMoves1;
	 board gameBoardMoves2;          //4 game boards for view and ships
	 board gameBoardShips1;
	 board gameBoardShips2;
	 gameBoardMoves1.createBoard(boardSize);
	 gameBoardMoves2.createBoard(boardSize);
	 gameBoardShips1.createBoard(boardSize);
	 gameBoardShips2.createBoard(boardSize);
	 std::cout<<"How many ships will each player get? (1-5)\n";
	 std::cin>>shipNumber;
	 //player 1 places ships
	 std::cout<<"Player 1, place your ships.\n";
	 try
	 {
		for(int i = 1; i<=shipNumber; i++)
		{
			gameBoardShips1.printBoard();
			Ship battleshipShip(i);
			std::cout<<"Where should your size "<<i<<" ship go? Enter x and y coordinates.\n";
			gameBoardShips1.placeShip(battleshipShip);
		}
	 }
	 catch(std::exception& e)
	 {
		 std::cout<<e.what();
	 }
	 //player 2 places ships
	 std::cout<<"Player 2, place your ships.\n";
	 try
	 {
		for(int i = 1; i<=shipNumber; i++)
		{
			gameBoardShips2.printBoard();
			Ship battleshipShip(i);
			std::cout<<"Where should your size "<<i<<" ship go? Enter x and y coordinates.\n";
			gameBoardShips2.placeShip(battleshipShip);
		}
	 }
	 catch(std::exception& e)
	 {
		 std::cout<<e.what();
	 }
	 //starts game by looping until game over is true
	 do
	 {
		 //asks player one for a move
		 //then asks player two for a move
		 gameBoardMoves1.printBoard();
		 gameBoardShips1.printBoard();
		 gameFunction(Player1);
		 gameBoardMoves2.printBoard();
		 gameBoardShips2.printBoard();
		 gameFunction(Player2);
	 }while(gameOver == false);
	 std::cout<<"Game over!\n";
 }