/** ------------------------------------------------------------------------
 * @file : ship.h
 * @author : Landen Doty
 * @assignment : EECS448 - Project 1
 * @brief : Simple class to define and store ship structure. Should be
            instantiated from the board class to implement with board
 * @date: 02-02-22
 *
 ------------------------------------------------------------------------ **/
#ifndef SHIP_H
#define SHIP_H

class Ship
{
  public:
    /**
       * @pre : None
       * @post : Ship array created, m_size set to size,
                  m_direction set to direction, and m_sunk set to false
       * @param : int size, char direction
       * @throw : runtime error if size less than 0 or larger than 5
                  is provided
       * @retun : N/A
    **/
    Ship(int size, char direction);
    /**
       * @pre : Ship array is defined
       * @post : Ship array pointer delete
       * @param : None
       * @throw : None
       * @retun : None
    **/
    ~Ship();
    /**
       * @pre : Ship array is defined
       * @post : Ship array updated at position to *
       * @param : int position
       * @throw : runtime error if position is out of bounds
       * @retun : None
    **/
    void hit(int position);
    /**
       * @pre : Ship array is defined
       * @post : Copy of ship array returned
       * @param : None
       * @throw : None
       * @retun : Pointer to a copy of the ship array
    **/
    char* get_ship();
    /**
       * @pre : Ship array is defined
       * @post : Ship size returned
       * @param : None
       * @throw : None
       * @retun : m_size
    **/
    int get_size();
    /**
       * @pre : Ship array is defined
       * @post : Boolean if ship is sunk (all *'s)
       * @param : None
       * @throw : None
       * @retun : m_sunk
    **/
    bool is_sunk();
  private:
    int m_size;
    char m_direction;
    char* m_ship;
    bool m_sunk;
};

#endif
