/*********************************************************************
** Program name: player.hpp
** Author: Jesse McKenna
** Date: 12/5/2017
** Description: Holds information unique to the player, including inventory
** of items and player's current state (win, lose, or playing)
*********************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>

class Player
{
public:
  enum State { NONE, PLAYING, WIN, LOSE };

private:
  State state; // player's current state (playing, win, or lose)

  const int INVENTORY_MAX = 2;
  std::vector<char> inv;

public:
  Player();
  ~Player();

  void setState(State newState);
  State getState();

  void addItem(char item);
  bool hasItem(char item);
  bool useItem(char item);
  void printInventory();
  bool inventoryFull();
};

#endif