#include <iostream>
#include "ship.h"
#include "game.h"
#include "board.h"
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
  Game myGame;
  myGame.fire("Player1");
  Board myBoard;
  myBoard.printBoard();*/

  //Ship testing with direction
  try{
    //horizontal ship of size 3
    Ship my_ship1(3, 'h');
    std::cout << my_ship1.get_direction() << "\n";
    //invalid ship direction
    //Ship my_ship2(3, 'x');
  }
  catch(std::exception &e)
  {
    std::cout << e.what() << "\n";
  }

  return(0);

}
