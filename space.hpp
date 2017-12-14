/*********************************************************************
** Program name: space.hpp
** Author: Jesse McKenna
** Date: 12/5/2017
** Description: Represents a space the player can move to within the text-based
** game. Each space contains pointers to adjacent spaces.
*********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include "player.hpp"

class Space
{
private:
  const char PLAYER_SYMBOL = 'X';

  Space* top = nullptr;
  Space* bottom = nullptr;
  Space* left = nullptr;
  Space* right = nullptr;

protected:
  bool player;
  bool walkable;
  char symbol;
  char defaultSymbol;

public:
  Space();
  virtual ~Space();

  enum Direction {UP, DOWN, LEFT, RIGHT};

  bool hasPlayer();
  void setPlayer(bool status);
  bool isWalkable();
  char getSymbol();

  void setAdjacent(Direction direction, Space* target);
  Space* getAdjacent(Direction direction);

  virtual void arrive(Player* player) = 0;
  virtual void inspect(Player* player) = 0;
  virtual void setSymbol(char symbol) {}
};

#endif