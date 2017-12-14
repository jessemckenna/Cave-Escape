/*********************************************************************
** Program name: holeSpace.hpp
** Author: Jesse McKenna
** Date: 12/5/2017
** Description: Represents a hole that the player can either fall into, ending
** the game, or fill with rocks to solve the puzzle.
*********************************************************************/

#ifndef HOLESPACE_HPP
#define HOLESPACE_HPP

#include "space.hpp"
#include "player.hpp"

class HoleSpace : public Space
{
private:

public:
  HoleSpace();
  virtual ~HoleSpace();
  virtual void arrive(Player* player);
  virtual void inspect(Player* player);
};

#endif