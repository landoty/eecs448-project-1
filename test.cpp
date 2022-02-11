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
    //EXAMPLE
    Ship my_ship1(3, 'h', 'D', 1);
    my_ship1.hit('E', 1);
    std::cout << my_ship1.get_ship() << '\n';
    Ship my_ship2(5, 'v', 'B', 1);
    my_ship2.hit('B', 3);
    std::cout << my_ship2.get_ship() << "\n";
    //Misses
    my_ship1.hit('C', 1);
    my_ship2.hit('C', 1);
  }
  catch(std::exception &e)
  {
    std::cout << e.what() << "\n";
  }

  return(0);

}
