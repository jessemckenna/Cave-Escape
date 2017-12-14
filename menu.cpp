/*********************************************************************
** Program name: menu.cpp
** Author: Jesse McKenna
** Date: 10/3/2017
** Description: Implementation file for menu functions.
*********************************************************************/

#include "menu.hpp"
#include "getInput.hpp"
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
