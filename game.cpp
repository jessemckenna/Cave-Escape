/*********************************************************************
** Program name: game.cpp
** Author: Jesse McKenna
** Date: 12/5/2017
** Description: Contains the game board and player object, and manages
** interactions between them
*********************************************************************/

#include "game.hpp"
#include "board.hpp"
#include "player.hpp"
#include "getInput.hpp"
#include <iostream>

// --- Constructor ---
Game::Game()
{
}

// --- Destructor ---
Game::~Game()
{
}

// --- play ---
// Runs the game
void Game::play()
{
  Board board;
  int steps = START_STEPS;
  player = new Player;
  player->setState(Player::PLAYING);

  std::cout << "You (X) are trapped in a cave.\n"
            << "Make it to the exit (E) before you run out of steps,\n"
            << "but be careful not to fall down any holes (@)!\n\n";

  do
  {
    std::cout << steps << " steps remaining\n";

    board.print();

    // Get user input
    std::cout << "\n"
              << "Move:   W       Inspect: E       Inventory: I       Quit: Q\n"
              << "      A S D\n";
    char input = getChar("WASDwasdEeIiQq");

    if (input == 'Q' || input == 'q')
    {
      player->setState(Player::LOSE);
    }
    else if (input == 'E' || input == 'e') // inspect current space
    {
      board.getPlayerSpace()->inspect(player);
    }
    else if (input == 'I' || input == 'i')
    {
      player->printInventory();
    }
    else
    {
      if(board.playerMove(input)) // pass WASD input as direction to move player
      {
        board.getPlayerSpace()->arrive(player);
        steps--; // player attempts to move; decrement steps if move successful
      }
    }

    // Game over if run out of steps
    if (steps < 0)
    {
      std::cout << "You ran out of steps!\n";
      player->setState(Player::LOSE);
    }

  } while (player->getState() == Player::PLAYING);

  // Display win or lose message
  switch (player->getState())
  {
    case Player::WIN:
      std::cout << "You win!\n";
      break;
    case Player::LOSE:
      std::cout << "Game over.\n";
      break;
  }

  delete player;
}