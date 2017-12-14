/*********************************************************************
** Program name: wallSpace.hpp
** Author: Jesse McKenna
** Date: 12/5/2017
** Description: Represents a wall space that the player cannot walk on.
*********************************************************************/

#ifndef WALLSPACE_HPP
#define WALLSPACE_HPP

#include "space.hpp"
#include "player.hpp"

class WallSpace : public Space
{
private:
public:
  WallSpace();
  virtual ~WallSpace();
  virtual void arrive(Player* player);
  virtual void inspect(Player* player);
};

#endif