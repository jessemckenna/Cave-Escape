/*********************************************************************
** Program name: player.hpp
** Author: Jesse McKenna
** Date: 12/5/2017
** Description: Holds information unique to the player, including inventory
** of items and player's current state (win, lose, or playing)
*********************************************************************/

//#ifndef PLAYER_HPP
//#define PLAYER_HPP

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

//#endif

/*********************************************************************
** Program name: space.hpp
** Author: Jesse McKenna
** Date: 12/5/2017
** Description: Represents a space the player can move to within the text-based
** game. Each space contains pointers to adjacent spaces.
*********************************************************************/

//#ifndef SPACE_HPP
//#define SPACE_HPP

//#include "player.hpp"

class Space
{
private:
  const char PLAYER_SYMBOL = 'X';

  Space* top = nullptr;
  Space* bottom = nullptr;
  Space* left = nullptr;
  Space* right = nullptr;

protected:
  bool player;
  bool walkable;
  char symbol;
  char defaultSymbol;

public:
  Space();
  virtual ~Space();

  enum Direction {UP, DOWN, LEFT, RIGHT};

  bool hasPlayer();
  void setPlayer(bool status);
  bool isWalkable();
  char getSymbol();

  void setAdjacent(Direction direction, Space* target);
  Space* getAdjacent(Direction direction);

  virtual void arrive(Player* player) = 0;
  virtual void inspect(Player* player) = 0;
  virtual void setSymbol(char symbol) {}
};

//#endif

/*********************************************************************
** Program name: board.hpp
** Author: Jesse McKenna
** Date: 12/5/2017
** Description: Manages the creation and printing of a game board consisting of
** linked spaces, each of which contains pointers to its adjacent spaces
*********************************************************************/

//#ifndef BOARD_HPP
//#define BOARD_HPP

//#include "space.hpp"
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

//#endif

/*********************************************************************
** Program name: emptySpace.hpp
** Author: Jesse McKenna
** Date: 12/5/2017
** Description: Represents an empty space that the player can walk on.
*********************************************************************/

//#ifndef EMPTYSPACE_HPP
//#define EMPTYSPACE_HPP

//#include "space.hpp"
//#include "player.hpp"

class EmptySpace : public Space
{
private:
public:
  EmptySpace();
  virtual ~EmptySpace();
  virtual void arrive(Player* player);
  virtual void inspect(Player* player);
  virtual void setSymbol(char symbol);
};

//#endif

/*********************************************************************
** Program name: exitSpace.hpp
** Author: Jesse McKenna
** Date: 12/5/2017
** Description: Represents the exit in the game; if the player reaches
** the exit space, the player wins the game.
*********************************************************************/

//#ifndef EXITSPACE_HPP
//#define EXITSPACE_HPP

//#include "space.hpp"
//#include "player.hpp"

class ExitSpace : public Space
{
private:

public:
  ExitSpace();
  virtual ~ExitSpace();
  virtual void arrive(Player* player);
  virtual void inspect(Player* player);
};

//#endif

/*********************************************************************
** Program name: game.hpp
** Author: Jesse McKenna
** Date: 12/5/2017
** Description: Contains the game board and player object, and manages
** interactions between them
*********************************************************************/

//#ifndef GAME_HPP
//#define GAME_HPP

//#include "player.hpp"

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

//#endif

/*********************************************************************
** Program name: getInput.hpp
** Author: Jesse McKenna
** Date: 9/27/2017
** Description: Helper functions for input validation 
*********************************************************************/

//#ifndef GETINPUT_HPP
//#define GETINPUT_HPP

#include <string>

int getInt();
int getInt(int min);
int getInt(int min, int max);

double getDouble();
double getDouble(double min);
double getDouble(double min, double max);

bool getYesNo();

char getChar();
char getChar(std::string validChars);

std::string getString();
std::string getFilename(std::string extension);

//#endif

/*********************************************************************
** Program name: holeSpace.hpp
** Author: Jesse McKenna
** Date: 12/5/2017
** Description: Represents a hole that the player can either fall into, ending
** the game, or fill with rocks to solve the puzzle.
*********************************************************************/

//#ifndef HOLESPACE_HPP
//#define HOLESPACE_HPP

//#include "space.hpp"
//#include "player.hpp"

class HoleSpace : public Space
{
private:

public:
  HoleSpace();
  virtual ~HoleSpace();
  virtual void arrive(Player* player);
  virtual void inspect(Player* player);
};

//#endif

/*********************************************************************
** Program name: menu.hpp
** Author: Jesse McKenna
** Date: 10/3/2017
** Description: Header file for menu functions.
*********************************************************************/

//#ifndef MENU_HPP
//#define MENU_HPP

#include <string>

class Menu
{
  private:
    int size;
    std::string* prompts; // dynamically allocated array of strings
    const int MAX_PROMPTS = 10;
  public:
    Menu(int size); // default constructor takes a menu size
    ~Menu(); // destructor
    void setPrompt(int number, std::string prompt); // set the desired prompt text
    int showMenu(); // displays the menu and returns the selection made
};

//#endif

/*********************************************************************
** Program name: symbols.hpp
** Author: Jesse McKenna
** Date: 11/19/2017
** Description: Defines the symbols used in the game to represent different
** types of spaces, items, etc.
*********************************************************************/

//#ifndef SYMBOLS_HPP
//#define SYMBOLS_HPP

// Spaces
const char EMPTY = ' ';
const char WALL = '#';
const char HOLE = '@';
const char EXIT = 'E';

// Items
const char ROCK = '^';
const char PICK = 'P';

//#endif

/*********************************************************************
** Program name: wallSpace.hpp
** Author: Jesse McKenna
** Date: 12/5/2017
** Description: Represents a wall space that the player cannot walk on.
*********************************************************************/

//#ifndef WALLSPACE_HPP
//#define WALLSPACE_HPP

//#include "space.hpp"
//#include "player.hpp"

class WallSpace : public Space
{
private:
public:
  WallSpace();
  virtual ~WallSpace();
  virtual void arrive(Player* player);
  virtual void inspect(Player* player);
};

//#endif

/*********************************************************************
** Program name: space.cpp
** Author: Jesse McKenna
** Date: 12/5/2017
** Description: Represents a space the player can move to within the text-based
** game. Each space contains pointers to adjacent spaces.
*********************************************************************/

//#include "space.hpp"

// --- Constructor ---
Space::Space()
{
}

// --- Destructor ---
Space::~Space()
{
}

// --- hasPlayer ---
// Return the value of member variable "player"
bool Space::hasPlayer()
{
  return player;
}

// --- setPlayer ---
void Space::setPlayer(bool status)
{
  player = status;

  if (player)
  {
    symbol = PLAYER_SYMBOL;
  }
  else
  {
    symbol = defaultSymbol;
  }
}

// --- isWalkable ---
// Return the value of member variable "walkable"
bool Space::isWalkable()
{
  return walkable;
}

// --- getSymbol ---
char Space::getSymbol()
{
  return symbol;
}

void Space::setAdjacent(Space::Direction direction, Space* target)
{
  switch (direction)
  {
    case UP:
      top = target;
      break;
    case DOWN:
      bottom = target;
      break;
    case LEFT:
      left = target;
      break;
    case RIGHT:
      right = target;
      break;
  }
}

Space* Space::getAdjacent(Space::Direction direction)
{
  switch (direction)
  {
    case UP:
      return top;
      break;
    case DOWN:
      return bottom;
      break;
    case LEFT:
      return left;
      break;
    case RIGHT:
      return right;
      break;
  }
  return nullptr;
}

/*********************************************************************
** Program name: player.cpp
** Author: Jesse McKenna
** Date: 12/5/2017
** Description: Holds information unique to the player, including inventory
** of items and player's current state (win, lose, or playing)
*********************************************************************/

//#include "player.hpp"
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

/*********************************************************************
** Program name: getInput.cpp
** Author: Jesse McKenna
** Date: 9/27/2017
** Description: Helper functions for input validation 
*********************************************************************/

#include <iostream>
#include <string>
#include <cctype>
//#include "getInput.hpp"

// --- getInt ---
// Requests user input until a valid int is entered. Rejects input containing
// any non-digit characters (except starting hyphen representing negative).
int getInt()
{
  // Initialize variables
  bool isClean;
  std::string input;
  int length = 0;
  int result;

  // Loop until an int value is returned
  do  
  {
    isClean = true;

    // Get entire line of user input
    std::getline(std::cin, input);

    // Reject input if length is less than 1 (ex. if user just pressed [enter])
    if (input.length() < 1)
    {
      isClean = false;
    }

    // Reject input if it contains any non-digit characters
    if (isClean && !isdigit(input.at(0)) && input.at(0)!='-')
    {
      isClean = false; // first character can be digit or - (for negative)
    }

    for (int i = 1; i < length && isClean; i++)
    {
      if (!isdigit(input.at(i))) // if any subsequent character is a non-digit
      {
        isClean = false; // set isClean to false and stop checking characters
      }
    }
  } while (!isClean);

  // Convert clean input to an int and assign to result
  result = std::stoi(input);
  return result;
}

// --- getInt(min) ---
// Requests user input until a valid int is entered. Rejects input containing
// any non-digit characters (except starting hyphen representing negative).
// Input must be greater than or equal to min.
int getInt(int min)
{
  int result;

  // Keep calling getInt until result is within acceptable range
  do
  {
    result = getInt();
  } while (result < min);
  
  return result;
}

// --- getInt(min, max) ---
// Requests user input until a valid int is entered. Rejects input containing
// any non-digit characters (except starting hyphen representing negative).
// Input must be between min and max, inclusive.
int getInt(int min, int max)
{
  int result;

  // Keep calling getInt until result is within acceptable range
  do
  {
    result = getInt();
  } while (result < min || result > max);
  
  return result;
}

// --- getDouble ---
double getDouble()
{
  // Initialize variables
  bool isClean;
  std::string input;
  int length = 0;
  double result;
  int decimalPoints; // count of decimal points (maximum of 1 is accepted)

  // Loop until a double value is returned
  do  
  {
    isClean = true;
    decimalPoints = 0;

    // Get entire line of user input
    std::getline(std::cin, input);

    // Reject input if length is less than 1 (ex. if user just pressed [enter])
    if (input.length() < 1)
    {
      isClean = false;
    }

    // First character can only be a digit, negative sign, or decimal point
    if (isClean && !isdigit(input.at(0)) && input.at(0)!='-' && input.at(0)!='.')
    {
      isClean = false;
    }
    else if (input.at(0) == '.')
    {
      decimalPoints++; // decimal chars are not rejected, but increment count
    }

    // Subsequent characters can only be digits or decimal points (max 1)
    for (int i = 1; i < length && isClean; i++)
    {
      if (input.at(i) == '.')
      {
        decimalPoints++; // decimal chars are not rejected, but increment count
      }
      else if (!isdigit(input.at(i))) // otherwise, if any char is non-digit
      {
        isClean = false; // set isClean to false and stop checking characters
      }
    }

    // Reject input if more than one decimal point was counted
    if (decimalPoints > 1)
    {
      isClean = false;
    }
  } while (!isClean);

  // Convert clean input to a double and assign to result
  result = std::stod(input);
  return result;
}

// --- getDouble(min) ---
// Input must be greater than or equal to min.
double getDouble(double min)
{
  double result;

  // Keep calling getDouble until result is within acceptable range
  do
  {
    result = getDouble();
  } while (result < min);
  
  return result;
}

// --- getDouble(min, max) ---
// Input must be between min and max, inclusive.
double getDouble(double min, double max)
{
  double result;

  // Keep calling getDouble until result is within acceptable range
  do
  {
    result = getDouble();
  } while (result < min || result > max);
  
  return result;
}

// --- getYesNo ---
// Requests user input until yes ("y", "yes") or no ("n", "no") is entered,
// then returns true for yes and false for no. Non-case-sensitive.
bool getYesNo()
{
  std::string input;

  while (true) // loop until appropriate response received
  {
    std::getline(std::cin, input); // get user input

    for (int i = 0, n = input.length(); i < n; i++)
    {
      input[i] = tolower(input[i]); // convert to lowercase (non-case-sensitive)
    }

    if (input == "y" || input == "yes")
    {
      return true;
    }

    if (input == "n" || input == "no")
    {
      return false;
    }
  }
}

// --- getChar ---
// Requests user input until a single character is provided
char getChar()
{
  std::string input;
  char result;

  // Loop until a char value is returned
  do
  {
    // Get entire line of user input
    std::getline(std::cin, input);

  } while (input.length() != 1); // reject if blank or longer than a single char

  result = input[0];
  return result;
}

// --- getChar ---
// Requests user input until a single character within validChars is provided
char getChar(std::string validChars)
{
  char result;
  bool isValid = false;

  // Loop until a char value is returned
  do
  {
    result = getChar();

    for (int i = 0, n = validChars.length(); i < n && !isValid; i++)
    {
      if (result == validChars.at(i))
      {
        isValid = true; // return once result char found in validChars string
      }
    }
  } while (!isValid); // reject if not within validChars

  return result;
}

// --- getString ---
// Requests user input until a string is entered; accepts any string containing
// only alphanumeric characters, periods, spaces, hyphens, pounds, and commas
std::string getString()
{
  std::string input;
  bool isText;
  char c;

  do
  {
    isText = true;
    std::getline(std::cin, input);

    for (int i = 0, n = input.length(); i < n && isText; i++)
    {
      c = input[i];
      if (!isalnum(c) && !isspace(c) && c != '.' && c != '-' && c != '#' &&
          c != ',')
      {
        isText = false; // reject string if non-permitted character is found
      }
    }

  } while (!isText || input.length() < 1);

  return input;
}

// --- getFilename ---
// Similar to getString, but appends the file extension if it was not included
// (ex. if requesting a .txt name and user enters "data", returns "data.txt")
std::string getFilename(std::string extension)
{
  int extLength = extension.length();

  // Add leading . character to extension if not included
  if (extLength > 0 && extension.at(0) != '.')
  {
    extension = '.' + extension;
  }

  std::string input = getString(); // get string from user
  int inputLength = input.length();

  bool hasExtension = false;
  if (inputLength > extLength) // check whether user added extension
  {
    hasExtension = true;
    for (int i = 0, j = inputLength - extLength;
        i < extLength && hasExtension; i++, j++)
    {
      if (input.at(j) != extension.at(i))
      {
        hasExtension = false;
      }
    }
  }

  if (!hasExtension)
  {
    input.append(extension);
  }

  return input;
}

/*********************************************************************
** Program name: menu.cpp
** Author: Jesse McKenna
** Date: 10/3/2017
** Description: Implementation file for menu functions.
*********************************************************************/

//#include "menu.hpp"
//#include "getInput.hpp"
#include <iostream>

// --- Menu ---
// Default constructor, called with the desired menu size; menu size cannot be
// greater than MAX_PROMPTS or it will be limited to MAX_PROMPTS
Menu::Menu(int menuSize)
{
  size = menuSize;

  if (size > MAX_PROMPTS)
  {
    size = MAX_PROMPTS; // restrict size to MAX_PROMPTS limit
  }
  
  prompts = new std::string[size];
}

// --- ~Menu ---
// Destructor; deletes the dynamically allocated string array "prompts"
Menu::~Menu()
{
  delete [] prompts;
  prompts = nullptr;
}

// --- setPrompt ---
// Accepts a prompt position and a string as arguments; puts the string into the
// "prompts" array at the specified position
void Menu::setPrompt(int number, std::string prompt) // set the desired prompt text
{
  if (number <= 0 || number > size)
  {
    return; // do nothing if invalid number referenced
  }

  prompts[number - 1] = prompt; // put entered prompt into the "prompts" array
}

// --- showMenu ---
// Displays the menu by printing each prompt in "prompts", then returns the
// selection made by the user
int Menu::showMenu()
{
  std::cout << "\n";
  for (int i = 0; i < size; i++)
  {
    std::cout << i + 1 << ". "; // prompt numbering, starting at 1
    std::cout << prompts[i]; // prompt text
    std::cout << "\n\n";
  }

  int choice;

  choice = getInt(1, size);

  return choice;
}

/*********************************************************************
** Program name: emptySpace.cpp
** Author: Jesse McKenna
** Date: 12/5/2017
** Description: Represents an empty space that the player can walk on.
*********************************************************************/

//#include "emptySpace.hpp"
//#include "player.hpp"
//#include "symbols.hpp"
//#include "menu.hpp"
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

/*********************************************************************
** Program name: exitSpace.hpp
** Author: Jesse McKenna
** Date: 12/5/2017
** Description: Represents the exit in the game; if the player reaches
** the exit space, the player wins the game.
*********************************************************************/

//#include "exitSpace.hpp"
//#include "player.hpp"
//#include "symbols.hpp"
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

/*********************************************************************
** Program name: holeSpace.cpp
** Author: Jesse McKenna
** Date: 12/5/2017
** Description: Represents a hole that the player can either fall into, ending
** the game, or fill with rocks to solve the puzzle.
*********************************************************************/

//#include "holeSpace.hpp"
//#include "player.hpp"
//#include "symbols.hpp"
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

/*********************************************************************
** Program name: wallSpace.cpp
** Author: Jesse McKenna
** Date: 12/5/2017
** Description: Represents a wall space that the player cannot walk on.
*********************************************************************/

//#include "wallSpace.hpp"
//#include "player.hpp"
//#include "symbols.hpp"

// --- Constructor ---
WallSpace::WallSpace()
{
  walkable = false;
  defaultSymbol = WALL;
  symbol = defaultSymbol;
}

// --- Destructor ---
WallSpace::~WallSpace()
{
}

// --- arrive ---
// Executes upon player arriving in a space;
// does nothing for a wall space because it is not walkable
void WallSpace::arrive(Player* player)
{
}

// --- inspect ---
// Executes upon player choosing to inspect current space;
// does nothing for a wall space because it is not walkable
void WallSpace::inspect(Player* player)
{
}

/*********************************************************************
** Program name: board.cpp
** Author: Jesse McKenna
** Date: 12/5/2017
** Description: Manages the creation and printing of a game board consisting of
** linked spaces, each of which contains pointers to its adjacent spaces
*********************************************************************/

//#include "board.hpp"
//#include "space.hpp"
//#include "emptySpace.hpp"
//#include "exitSpace.hpp"
//#include "holeSpace.hpp"
//#include "wallSpace.hpp"
//#include "symbols.hpp" // constant chars for board symbols
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

/*********************************************************************
** Program name: game.cpp
** Author: Jesse McKenna
** Date: 12/5/2017
** Description: Contains the game board and player object, and manages
** interactions between them
*********************************************************************/

//#include "game.hpp"
//#include "board.hpp"
//#include "player.hpp"
//#include "getInput.hpp"
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

/*********************************************************************
** Program name: main.cpp
** Author: Jesse McKenna
** Date: 11/19/2017
** Description: Runs the game contained in game.hpp until the player chooses to
** quit
*********************************************************************/

//#include "game.hpp"
//#include "menu.hpp"
//#include "getInput.hpp"
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