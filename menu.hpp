/*********************************************************************
** Program name: menu.hpp
** Author: Jesse McKenna
** Date: 10/3/2017
** Description: Header file for menu functions.
*********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

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

#endif
