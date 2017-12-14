/*********************************************************************
** Program name: emptySpace.hpp
** Author: Jesse McKenna
** Date: 12/5/2017
** Description: Represents an empty space that the player can walk on.
*********************************************************************/

#ifndef EMPTYSPACE_HPP
#define EMPTYSPACE_HPP

#include "space.hpp"
#include "player.hpp"

class EmptySpace : public Space
{
private:
public:
  EmptySpace();
  virtual ~EmptySpace();
  virtual void arrive(Player* player);
  virtual void inspect(Player* player);
  virtual void setSymbol(char symbol);
};

#endif