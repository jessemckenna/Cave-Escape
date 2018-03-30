/*********************************************************************
** Program name: board.cpp
** Author: Jesse McKenna
** Date: 12/5/2017
** Description: Manages the creation and printing of a game board consisting of
** linked spaces, each of which contains pointers to its adjacent spaces
*********************************************************************/

#include "board.hpp"
#include "space.hpp"
#include "emptySpace.hpp"
#include "exitSpace.hpp"
#include "holeSpace.hpp"
#include "wallSpace.hpp"
#include "symbols.hpp" // constant chars for board symbols
#include <iostream>
#include <fstream>
#include <string>

// --- Constructor ---
Board::Board()
{
  readMap();

  origin = createSpace(map.at(0));

  // Create board rows as linked structure
  Space* current = origin;
  Space* next;

  // Create first row, left to right
  for (int j = 1; j < boardCols; j++)
  {
    next = createSpace(map.at(j)); // create new space based on map textfile

    current->setAdjacent(Space::RIGHT, next); // link to existing spaces
    next->setAdjacent(Space::LEFT, current);

    current = next; // move to next space
  }

  // Create subsequent rows, left to right, top to bottom
  Space* rowStart = origin;
  Space* above;
  for (int i = 1; i < boardRows; i++)
  {
    // Create new row
    next = createSpace(map.at(i * boardCols));
    rowStart->setAdjacent(Space::DOWN, next); // link to previous row
    next->setAdjacent(Space::UP, rowStart);

    // Move to new row
    above = rowStart; // set above to start of previous row
    rowStart = next; // move to start of new row
    current = rowStart; // set current to start of new row

    // Create spaces in new row
    for (int j = 1; j < boardCols; j++)
    {
      next = createSpace(map.at(i * boardCols + j)); // create new space

      above = above->getAdjacent(Space::RIGHT); // set above to space above next

      next->setAdjacent(Space::UP, above); // link to existing spaces
      above->setAdjacent(Space::DOWN, next);
      next->setAdjacent(Space::LEFT, current);
      current->setAdjacent(Space::RIGHT, next);

      current = next; // move to next space
    }
  }

  // Put player at space below and to the right of the origin, i.e. [1,1]
  playerSpace = origin->getAdjacent(Space::DOWN)->getAdjacent(Space::RIGHT);
  playerSpace->setPlayer(true);
}

// --- Destructor ---
Board::~Board()
{
  Space* rowStart = origin;
  Space* current;
  Space* garbage;
  for (int i = 0; i < boardRows; i++)
  {
    current = rowStart;
    rowStart = rowStart->getAdjacent(Space::DOWN); // prepare for next loop
    for (int j = 0; j < boardCols; j++)
    {
      // Select node to be deleted
      garbage = current;
      current = current->getAdjacent(Space::RIGHT); // prepare for next loop

      // Delete node
      garbage->setAdjacent(Space::UP, nullptr);
      garbage->setAdjacent(Space::DOWN, nullptr);
      garbage->setAdjacent(Space::LEFT, nullptr);
      garbage->setAdjacent(Space::DOWN, nullptr);
      delete garbage;
    }
  }
}

// --- getPlayerSpace ---
// Return pointer to player's current location
Space* Board::getPlayerSpace()
{
  return playerSpace;
}

// --- print ---
// Prints the board
void Board::print()
{
  std::cout << "\n";

  Space* rowStart = origin;
  Space* current;
  for (int i = 0; i < boardRows; i++)
  {
    current = rowStart;
    rowStart = rowStart->getAdjacent(Space::DOWN); // prepare to print next row
    for (int j = 0; j < boardCols; j++)
    {
      std::cout << current->getSymbol() << " ";
      current = current->getAdjacent(Space::RIGHT); // move right to next space
    }
    std::cout << "\n";
  }
}

// --- playerMove ---
// Moves player in given direction; returns true if player was moved
bool Board::playerMove(char direction)
{
  Space* target;

  if (direction == 'W' || direction == 'w') // up
  {
    target = playerSpace->getAdjacent(Space::UP);
  }
  else if (direction == 'A' || direction == 'a') // left
  {
    target = playerSpace->getAdjacent(Space::LEFT);
  }
  else if (direction == 'S' || direction == 's') // down
  {
    target = playerSpace->getAdjacent(Space::DOWN);
  }
  else if (direction == 'D' || direction == 'd') // right
  {
    target = playerSpace->getAdjacent(Space::RIGHT);
  }
  else
  {
    return false; // invalid input
  }

  if (target != nullptr && target->isWalkable()) // if target is valid
  {
    playerSpace->setPlayer(false); // remove player from old location
    playerSpace = target;
    target->setPlayer(true); // assign player to new location

    return true;
  }

  return false; // return false if target was nullptr or not walkable
}

// --- readMap ---
// Gets the map data from .txt file to prepare for board creation
void Board::readMap()
{
  std::ifstream mapFile;
  mapFile.open(mapFilename, std::ios::in);

  if (!mapFile)
  {
	  map = "######## @  ^## ^#  ##P#  ###^# @@###^@@E########"; // default map
	  boardRows = 7;
	  boardCols = 7;
	  return;
  }

  boardRows = 0;
  boardCols = 0;

  std::string line = "";

  getline(mapFile, line); // read first line from mapFile
  boardCols = line.length(); // number of columns = length of first line
  map += line;
  boardRows++;

  while (getline(mapFile, line)) // read each subsequent line from mapFile
  {
    map += line;
    boardRows++; // number of rows = number of lines read in from file
  }

  mapFile.close();
}

// --- createSpace ---
// Accepts a char read from the 'map' in readMap, then allocates and returns a
// pointer to a Space of the type that corresponds to the given char symbol
Space* Board::createSpace(char type)
{
  Space* newSpace;

  if (type == WALL)
  {
    newSpace = new WallSpace;
  }
  else if (type == HOLE)
  {
    newSpace = new HoleSpace;
  }
  else if (type == EXIT)
  {
    newSpace = new ExitSpace;
  }
  else if (type == ROCK || type == PICK)
  {
    newSpace = new EmptySpace;
    newSpace->setSymbol(type);
  }
  else
  {
    newSpace = new EmptySpace;
  }

  return newSpace;
}
