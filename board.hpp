/*********************************************************************
** Program name: board.hpp
** Author: Jesse McKenna
** Date: 12/5/2017
** Description: Manages the creation and printing of a game board consisting of
** linked spaces, each of which contains pointers to its adjacent spaces
*********************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

#include "space.hpp"
#include <string>

class Board
{
private:
  int boardRows;
  int boardCols;

  Space* origin;
  Space* playerSpace;

  const std::string mapFilename = "map.txt";
  std::string map; // string of chars used to read map.txt and create board from it

public:
  Board();
  ~Board();

  // Get and set methods
  Space* getPlayerSpace();

  // Gameplay methods
  void print();
  bool playerMove(char direction);

  // Board creation methods
  void readMap(); // reads a 'map' of the game board from .txt file into string
  Space* createSpace(char type); // allocates and returns a Space of given type
};

#endif