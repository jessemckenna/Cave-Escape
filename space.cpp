/*********************************************************************
** Program name: space.cpp
** Author: Jesse McKenna
** Date: 12/5/2017
** Description: Represents a space the player can move to within the text-based
** game. Each space contains pointers to adjacent spaces.
*********************************************************************/

#include "space.hpp"

// --- Constructor ---
Space::Space()
{
}

// --- Destructor ---
Space::~Space()
{
}

// --- hasPlayer ---
// Return the value of member variable "player"
bool Space::hasPlayer()
{
  return player;
}

// --- setPlayer ---
void Space::setPlayer(bool status)
{
  player = status;

  if (player)
  {
    symbol = PLAYER_SYMBOL;
  }
  else
  {
    symbol = defaultSymbol;
  }
}

// --- isWalkable ---
// Return the value of member variable "walkable"
bool Space::isWalkable()
{
  return walkable;
}

// --- getSymbol ---
char Space::getSymbol()
{
  return symbol;
}

void Space::setAdjacent(Space::Direction direction, Space* target)
{
  switch (direction)
  {
    case UP:
      top = target;
      break;
    case DOWN:
      bottom = target;
      break;
    case LEFT:
      left = target;
      break;
    case RIGHT:
      right = target;
      break;
  }
}

Space* Space::getAdjacent(Space::Direction direction)
{
  switch (direction)
  {
    case UP:
      return top;
      break;
    case DOWN:
      return bottom;
      break;
    case LEFT:
      return left;
      break;
    case RIGHT:
      return right;
      break;
  }
  return nullptr;
}