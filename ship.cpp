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

Ship::Ship(int size, char direction, char starting_horiz, int starting_vert)
{
  if(size > 5 || size < 0)
  {
    throw(std::runtime_error("Ships must be of size 1-5\n"));
  }
  else if(direction != 'h' && direction != 'v')
  {
    throw(std::runtime_error("Ships must be of direction v(ertical) or h(orizontal)"));
  }
  else if(starting_vert > 10 || starting_vert < 1)
  {
    throw(std::runtime_error("Invalid vertical starting position\n"));
  }
  else if(starting_horiz < 'a' || starting_horiz > 'j')
  {
    throw(std::runtime_error("Invalid horizontal starting position\n"));
  }
  else
  {
    m_ship = new char[size];
    m_size = size;
    m_direction = direction;
    m_v_start = starting_vert;
    m_h_start = starting_horiz;
    for(int i=0; i<m_size; i++)
    {
      m_ship[i] = 's';
    }
    m_sunk = false;
  }
}

void Ship::hit(char horiz_coord, int vert_coord)
{
    /*
      Assumes coordinates being passed are valid within the 10x10 board.
      Only checks if the shot is a hit or miss
    */
    if(m_direction == 'h')
    {
      //Checks if fire is within the same row and within the range of the ship length
      if(horiz_coord < m_h_start || (horiz_coord > (m_h_start + m_size - 1)) || vert_coord != m_v_start)
      {
        throw(std::runtime_error("Miss!"));
      }
      else
      {
        m_ship[horiz_coord - m_h_start] = '*';
      }
    }
    else if(m_direction == 'v')
    {
      //Checks if fire is within the same column and within the range of the ship length
      if(vert_coord < m_v_start || (vert_coord > (m_v_start + m_size - 1)) || horiz_coord != m_h_start)
      {
        throw(std::runtime_error("Miss!"));
      }
      else
      {
        m_ship[vert_coord - m_v_start] = '*';
      }
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

int Ship::get_vert_start()
{
  return(m_v_start);
}

char Ship::get_horiz_start()
{
  return(m_h_start);
}

char Ship::get_direction()
{
  return(m_direction);
}

bool Ship::is_sunk()
{
  for(int i=0; i<m_size; i++)
  {
    if(m_ship[i] == '*')
    {
      m_sunk = true;
    }
    else
    {
      //If an s is seen, the ship is not sunk and can break the checking loop
      m_sunk = false;
      break;
    }
  }
  return(m_sunk);
}

Ship::~Ship()
{
  delete[] m_ship;
}
