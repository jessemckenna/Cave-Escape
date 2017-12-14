/*********************************************************************
** Program name: emptySpace.cpp
** Author: Jesse McKenna
** Date: 12/5/2017
** Description: Represents an empty space that the player can walk on.
*********************************************************************/

#include "emptySpace.hpp"
#include "player.hpp"
#include "symbols.hpp"
#include "menu.hpp"
#include <iostream>

// --- Constructor ---
EmptySpace::EmptySpace()
{
  walkable = true;
  defaultSymbol = EMPTY;
  symbol = defaultSymbol;
}

// --- Destructor ---
EmptySpace::~EmptySpace()
{
}

// --- arrive ---
// Executes upon player arriving in a space;
// does nothing for an empty space
void EmptySpace::arrive(Player* player)
{
}

// --- inspect ---
// Executes upon player choosing to inspect current space
void EmptySpace::inspect(Player* player)
{
  if (defaultSymbol == ROCK)
  {
    std::cout << "\nA formation of large rocks.\n";

    if (player->hasItem(PICK) && player->inventoryFull())
    {
      std::cout << "You have a pickaxe, but your inventory is full.\n";
    }
    else if (player->hasItem(PICK) && !player->inventoryFull())
    {
      std::cout << "You have a pickaxe.\n";
      Menu mineMenu(2);
      mineMenu.setPrompt(1, "Mine the rocks");
      mineMenu.setPrompt(2, "Do nothing");

      if (mineMenu.showMenu() == 1) // player chooses to mine rocks
      {
        player->addItem(ROCK); // add rock to inventory
        defaultSymbol = EMPTY; // remove rock from space
      }
    }
  }
  else if (defaultSymbol == PICK)
  {
    std::cout << "\nA pickaxe.\n";

    if (!player->inventoryFull())
    {
      Menu pickMenu(2);
      pickMenu.setPrompt(1, "Take the pickaxe");
      pickMenu.setPrompt(2, "Do nothing");

      if (pickMenu.showMenu() == 1) // player chooses to take pickaxe
      {
        player->addItem(PICK); // add pick to inventory
        defaultSymbol = EMPTY; // remove pick from space
      }
    }
  }
  else
  {
    std::cout << "\nFound nothing of interest.\n";
  }
}

// --- setSymbol ---
// Unique to EmptySpace; used to modify the space's symbol depending on whether
// an item is present or not
void EmptySpace::setSymbol(char symbol)
{
  if (symbol == WALL || symbol == HOLE || symbol == EXIT)
  {
    return; // can't set empty space to symbol for wall, hole, or exit
  }
  else
  {
    defaultSymbol = symbol;
    this->symbol = defaultSymbol;
  }
}