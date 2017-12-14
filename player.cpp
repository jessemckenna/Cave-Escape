/*********************************************************************
** Program name: player.cpp
** Author: Jesse McKenna
** Date: 12/5/2017
** Description: Holds information unique to the player, including inventory
** of items and player's current state (win, lose, or playing)
*********************************************************************/

#include "player.hpp"
#include <iostream>

// --- Constructor ---
Player::Player()
{
  state = NONE;
}

// --- Destructor ---
Player::~Player()
{
  inv.clear();
}

// --- setState ---
void Player::setState(Player::State newState)
{
  state = newState;
}

// --- getState ---
Player::State Player::getState()
{
  return state;
}

// --- addItem ---
// If there is room in the inventory, add the given item
void Player::addItem(char item)
{
  if (inv.size() <= INVENTORY_MAX)
  {
    inv.push_back(item);
  }
}

// --- hasItem ---
// Search for given item in inventory, and return true if found
bool Player::hasItem(char item)
{
  for (std::vector<char>::iterator i = inv.begin(); i != inv.end(); i++)
  {
    if (*i == item) // if item found
    {
      return true; // delete item from inventory
    }
  }
  return false;
}

// --- useItem ---
// Search for given item in inventory, remove from inventory and return true
// if found
bool Player::useItem(char item)
{
  for (std::vector<char>::iterator i = inv.begin(); i != inv.end(); i++)
  {
    if (*i == item) // if item found
    {
      inv.erase(i); // delete item from inventory
      return true;
    }
  }
  return false;
}

// --- printInventory ---
// Print each char in inventory
void Player::printInventory()
{
  if (inv.size() == 0)
  {
    std::cout << "\nInventory is empty.\n";
  }
  else
  {
    std::cout << "\nInventory: ";
    for (std::vector<char>::iterator i = inv.begin(); i != inv.end(); i++)
    {
      std::cout << *i << " ";
    }
    std::cout << "\n";
  }
}

// --- inventoryFull ---
// Return true if inventory is full
bool Player::inventoryFull()
{
  return inv.size() >= INVENTORY_MAX;
}