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
	 gameOver = false;
	 boardSize = 10;
	 shipNumber = 0;
 }
 
 void Executive::play()
 {
	 Game gameFunction;
	 std::cout<<"Welcome to Battleship!\n";
//	 std::cin>>boardSize;
//	 creates a board object to make the game board and then displays it
	 Board gameBoardMoves1;
	 Board gameBoardMoves2;          //4 game boards for view and ships
	 Board gameBoardShips1;
	 Board gameBoardShips2;
	 char xCoordinate;
	 int yCoordinate;
	 char direction;
	 std::string Player1 = " ";
	 std::string Player2 = " ";
/*	 gameBoardMoves1.createBoard(boardSize);
	 gameBoardMoves2.createBoard(boardSize);
	 gameBoardShips1.createBoard(boardSize);
	 gameBoardShips2.createBoard(boardSize);*/
	 std::cout<<"How many ships will each player get? (1-5)\n";
	 std::cin>>shipNumber;
	 //player 1 places ships
	 std::cout<<"Player 1, place your ships.\n";
	 /*
	 try
	 {
		for(int i = 1; i<=shipNumber; i++)
		{
			gameBoardShips1.printBoard();
			Ship battleshipShip(i);
			std::cout<<"Where should your size "<<i<<" ship go? Enter row, column, and direction.\n";
			std::cout<<"Row(1-10): ";
			std::cin>>yCoordinate;
			std::cout<<"Column(A-J): ";
			std::cin>>xCoordinate;
			std::cout<<"Direction(h/v): ";
			std::cin>>direction;
			gameBoardShips1.placeShip(battleshipShip, xCoordinate, yCoordinate, direction);
		}
	 }
	 catch(std::exception& e)
	 {
		 std::cout<<e.what();
	 }*/
	 for(int i = 1; i<=shipNumber; i++)
	 {
		gameBoardShips1.printBoard();
		Ship battleshipShip(i);
		std::cout<<"Where should your size "<<i<<" ship go? Enter row, column, and direction.\n";
		std::cout<<"Row(1-10): ";
		std::cin>>yCoordinate;
		std::cout<<"Column(A-J): ";
		std::cin>>xCoordinate;
		std::cout<<"Direction(h/v): ";
		std::cin>>direction;
		try
		{
			gameBoardShips1.placeShip(battleshipShip, xCoordinate, yCoordinate, direction);
		}
		catch(std::exception& e)
		{
			std::cout<<e.what();
		}
	 }
	 //player 2 places ships
	 std::cout<<"Player 2, place your ships.\n";
	 /*
	 try
	 {
		for(int i = 1; i<=shipNumber; i++)
		{
			gameBoardShips2.printBoard();
			Ship battleshipShip(i);
			std::cout<<"Where should your size "<<i<<" ship go? Enter row, column, and direction.\n";
			std::cout<<"Row(1-10): ";
			std::cin>>yCoordinate;
			std::cout<<"Column(A-J): ";
			std::cin>>xCoordinate;
			std::cout<<"Direction(h/v): ";
			std::cin>>direction;
			gameBoardShips2.placeShip(battleshipShip, xCoordinate, yCoordinate, direction);
		}
	 }
	 catch(std::exception& e)
	 {
		 std::cout<<e.what();
	 }*/
	 for(int i = 1; i<=shipNumber; i++)
	 {
		gameBoardShips2.printBoard();
		Ship battleshipShip(i);
		std::cout<<"Where should your size "<<i<<" ship go? Enter row, column, and direction.\n";
		std::cout<<"Row(1-10): ";
		std::cin>>yCoordinate;
		std::cout<<"Column(A-J): ";
		std::cin>>xCoordinate;
		std::cout<<"Direction(h/v): ";
		std::cin>>direction;
		try
		{
			gameBoardShips2.placeShip(battleshipShip, xCoordinate, yCoordinate, direction);
		}
		catch(std::exception& e)
		{
			std::cout<<e.what();
		}
	 }
	 //starts game by looping until game over is true
	 do
	 {
		 //asks player one for a move
		 //then asks player two for a move
		 gameBoardMoves1.printBoard();
		 gameBoardShips1.printBoard();
		 gameFunction.fire(Player1);
		 gameBoardMoves2.printBoard();
		 gameBoardShips2.printBoard();
		 gameFunction.fire(Player2);
	 }while(gameFunction.gameEndCheck() == false);
	 std::cout<<"Game over!\n";
 }
 
 Executive::~Executive()
 {
 }