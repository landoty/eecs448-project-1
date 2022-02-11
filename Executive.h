/** ------------------------------------------------------------------------
 * @file : Executive.h
 * @author : Aidan Bowen
 * @assignment : EECS448 - Project 1
 * @brief : Class that runs the game and uses methods implemented by other
			classes to control the functions of the game
 * @date: 02-06-21
 *
 ------------------------------------------------------------------------ **/
 #ifndef EXECUTIVE_H
 #define EXECUTIVE_H
 
 class Executive
 {
	 private:
	 bool gameOver;
	 int boardSize;
	 int shipNumber;
	 
	 public:
	 Executive();
	 void play();
 }