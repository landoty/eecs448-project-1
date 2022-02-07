#include <iostream>
#include "ship.h"

int main()
{
  int size;
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
  return(0);
}
