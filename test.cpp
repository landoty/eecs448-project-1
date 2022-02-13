#include <iostream>
#include "ship.h"
#include "game.h"
#include "board.h"
#include "Executive.h"
int main()
{
  /*int size;
  std::cout << "Ship size: ";
  std::cin >> size;

  Ship my_ship(size);
  char* ship_arr;
  ship_arr = new char[my_ship.get_size()];
  for(int i=0; i<my_ship.get_size(); i++)
  {
    std::cout << my_ship.get_ship()[i] << "\n";
    ship_arr[i] = my_ship.get_ship()[i];
    std::cout << "Ship arr: " << &ship_arr << '\n';
  }
  delete[] ship_arr;
  //game Testing Methods
  Executive exec;
  exec.play();
  Game myGame;
  myGame.fire("Player1");
  Board myBoard;
  myBoard.printBoard();*/

  //Ship testing with direction
  /*
  try{
    //EXAMPLE
    Ship my_ship1(3, 'h', 'd', 1);
    std::cout << my_ship1.get_horiz_start() << my_ship1.get_vert_start() << "\n";
    my_ship1.hit('E', 1);
    std::cout << my_ship1.get_ship() << '\n';
    Ship my_ship2(5, 'v', 'b', 1);
    my_ship2.hit('b', 3);
    std::cout << my_ship2.get_ship() << "\n";
    //Misses
    my_ship1.hit('c', 1);
    my_ship2.hit('c', 1);
  }
  catch(std::exception &e)
  {
    std::cout << e.what() << "\n";
  }*/
  Executive exec;
  exec.play();

  return(0);
}
