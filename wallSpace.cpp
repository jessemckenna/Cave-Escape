/*********************************************************************
** Program name: wallSpace.cpp
** Author: Jesse McKenna
** Date: 12/5/2017
** Description: Represents a wall space that the player cannot walk on.
*********************************************************************/

#include "wallSpace.hpp"
#include "player.hpp"
#include "symbols.hpp"

// --- Constructor ---
WallSpace::WallSpace()
{
  walkable = false;
  defaultSymbol = WALL;
  symbol = defaultSymbol;
}

// --- Destructor ---
WallSpace::~WallSpace()
{
}

// --- arrive ---
// Executes upon player arriving in a space;
// does nothing for a wall space because it is not walkable
void WallSpace::arrive(Player* player)
{
}

// --- inspect ---
// Executes upon player choosing to inspect current space;
// does nothing for a wall space because it is not walkable
void WallSpace::inspect(Player* player)
{
}