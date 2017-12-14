/*********************************************************************
** Program name: exitSpace.hpp
** Author: Jesse McKenna
** Date: 12/5/2017
** Description: Represents the exit in the game; if the player reaches
** the exit space, the player wins the game.
*********************************************************************/

#include "exitSpace.hpp"
#include "player.hpp"
#include "symbols.hpp"
#include <iostream>

// --- Constructor ---
ExitSpace::ExitSpace()
{
  walkable = true;
  defaultSymbol = EXIT;
  symbol = defaultSymbol;
}

// --- Destructor ---
ExitSpace::~ExitSpace()
{
}

// --- arrive ---
// Executes upon player arriving in a space;
// does nothing for an empty space
void ExitSpace::arrive(Player* player)
{
  std::cout << "You reached the exit!\n";
  player->setState(Player::WIN);
}

// --- inspect ---
// Executes upon player choosing to inspect current space
void ExitSpace::inspect(Player* player)
{
}