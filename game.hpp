/*********************************************************************
** Program name: game.hpp
** Author: Jesse McKenna
** Date: 12/5/2017
** Description: Contains the game board and player object, and manages
** interactions between them
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"

class Game
{
private:
  const int START_STEPS = 22;
  Player* player;

public:
  Game();
  ~Game();
  void play();
};

#endif