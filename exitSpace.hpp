/*********************************************************************
** Program name: exitSpace.hpp
** Author: Jesse McKenna
** Date: 12/5/2017
** Description: Represents the exit in the game; if the player reaches
** the exit space, the player wins the game.
*********************************************************************/

#ifndef EXITSPACE_HPP
#define EXITSPACE_HPP

#include "space.hpp"
#include "player.hpp"

class ExitSpace : public Space
{
private:

public:
  ExitSpace();
  virtual ~ExitSpace();
  virtual void arrive(Player* player);
  virtual void inspect(Player* player);
};

#endif