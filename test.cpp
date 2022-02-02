#include <iostream>
#include "ship.h"

int main()
{
  int size;
  std::cout << "Ship size: ";
  std::cin >> size;

  Ship my_ship(size);
  char* copy_ship = my_ship.get_ship();
  int copy_length = my_ship.get_size();
  for(int i=0; i<copy_length; i++)
  {
    std::cout << copy_ship[i];
    my_ship.hit(i);
  }

  copy_ship = my_ship.get_ship();
  copy_length = my_ship.get_size();
  for(int i=0; i<copy_length; i++)
  {
    std::cout << copy_ship[i];
  }
  std::cout << my_ship.is_sunk();
  std::cout << "\n";

  Ship second_ship(10);
  return(0);
}
