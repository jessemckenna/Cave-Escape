/*********************************************************************
** Program name: holeSpace.cpp
** Author: Jesse McKenna
** Date: 12/5/2017
** Description: Represents a hole that the player can either fall into, ending
** the game, or fill with rocks to solve the puzzle.
*********************************************************************/

#include "holeSpace.hpp"
#include "player.hpp"
#include "symbols.hpp"
#include <iostream>

// --- Constructor ---
HoleSpace::HoleSpace()
{
  walkable = true;
  defaultSymbol = HOLE;
  symbol = defaultSymbol;
}

// --- Destructor ---
HoleSpace::~HoleSpace()
{
}

// --- arrive ---
// Executes upon player arriving in a space
void HoleSpace::arrive(Player* player)
{
  if (defaultSymbol == EMPTY)
  {
    return; // if hole has been removed from space, do nothing
  }

  if (player->hasItem(ROCK))
  {
    std::cout << "You filled the hole in the ground with rocks to cross it.\n";
    player->useItem(ROCK); // remove rock from player inventory
    defaultSymbol = EMPTY; // remove hole from space by changing symbol to empty
  }
  else
  {
    std::cout << "\nYou fell in a hole!\n";
    player->setState(Player::LOSE);
  }
}

// --- inspect ---
// Executes upon player choosing to inspect current space
void HoleSpace::inspect(Player* player)
{
}