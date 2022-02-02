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

Ship::Ship(int size)
{
  if(m_size > 5 || m_size < 0)
  {
    throw(std::runtime_error("Ships must be of size 1-5\n"));
  }
  else
  {
    m_ship = new char[size];
    m_size = size;
    for(int i=0; i<m_size; i++)
    {
      m_ship[i] = 's';
    }
    m_sunk = false;
  }
}

void Ship::hit(int position)
{
  if(m_size > 5 || m_size < 0)
  {
    throw(std::runtime_error("Ships must be of size 1-5\n"));
  }
  else
  {
    m_ship[position] = '*';
  }
}

char* Ship::get_ship()
{
  char* return_ship;
  return_ship = new char[m_size];
  for(int i=0; i<m_size; i++)
  {
    return_ship[i] = m_ship[i];
  }
  return(return_ship);
}

int Ship::get_size()
{
  return(m_size);
}

bool Ship::is_sunk()
{
  for(int i=0; i<m_size; i++)
  {
    if(m_ship[i] != '*')
    {
      m_sunk = true;
    }
  }
  return(m_sunk);
}

Ship::~Ship()
{
  delete m_ship;
}
