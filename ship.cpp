/** ------------------------------------------------------------------------
 * @file : ship.cpp
 * @author : Landen Doty
 * @assignment : EECS448 - Project 1
 * @brief : Simple class to define and store ship structure. Should be
            instantiated from the board class to implement with board
 * @date: 02-02-22
 *
 ------------------------------------------------------------------------ **/
#include <iostream>
#include <string>
#include "ship.h"

Ship::Ship(int size, char direction)
{
  if(size > 5 || size < 0)
  {
    throw(std::runtime_error("Ships must be of size 1-5\n"));
  }
  else if(direction != 'h' && direction != 'v')
  {
    throw(std::runtime_error("Ships must be of direction v(ertical) or h(orizontal)"));
  }
  else
  {
    m_ship = new char[size];
    m_size = size;
    m_direction = direction;
    for(int i=0; i<m_size; i++)
    {
      m_ship[i] = 's';
    }
    m_sunk = false;
  }
}

void Ship::hit(int position)
{
  if(position > m_size || position < 1)
  {
    throw(std::runtime_error("Firing out of range\n"));
  }
  else
  {
    /*
      A ship of length n has n-many positions to hit.
      Calling hit on position 1 will mark the 0 index
      of m_ship arr as hit and so on
    */
    m_ship[position-1] = '*';
  }
}

char* Ship::get_ship()
{
  return(m_ship);
}

int Ship::get_size()
{
  return(m_size);
}

bool Ship::is_sunk()
{
  for(int i=0; i<m_size; i++)
  {
    if(m_ship[i] == '*')
    {
      m_sunk = true;
    }
  }
  return(m_sunk);
}

Ship::~Ship()
{
  delete[] m_ship;
}
