/*********************************************************************
** Program name: main.cpp
** Author: Jesse McKenna
** Date: 11/19/2017
** Description: Runs the game contained in game.hpp until the player chooses to
** quit
*********************************************************************/

#include "game.hpp"
#include "menu.hpp"
#include "getInput.hpp"
#include <iostream>

int main()
{
  // Introduction
  std::cout
    << "    mm         mm         mm\n"
    << " /^(  )^\\   /^(  )^\\   /^(  )^\\\n"
    << " \\,(..),/   \\,(..),/   \\,(..),/\n"
    << "   V~~V       V~~V       V~~V\n" // from http://chris.com/ascii/index.php?art=animals/bats

    << "\n--- Welcome to Cave Escape! ---\n";

  // Main menu
  Menu mainMenu(2);
  mainMenu.setPrompt(1, "Play");
  mainMenu.setPrompt(2, "Exit");
  int mainChoice = mainMenu.showMenu();
  if (mainChoice == 2)
  {
    return 0;
  }

  // Game setup
  Menu replayMenu(2); // play again menu displayed after round end
  replayMenu.setPrompt(1, "Play again");
  replayMenu.setPrompt(2, "Quit");
  int replayChoice;

  Game game;

  // Game loop
  do
  {
    game.play();

    // Ask if player wants to play again
    replayChoice = replayMenu.showMenu();
  } while (replayChoice == 1); // repeat game until player chooses to quit

  return 0;
}