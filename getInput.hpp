/*********************************************************************
** Program name: getInput.hpp
** Author: Jesse McKenna
** Date: 9/27/2017
** Description: Helper functions for input validation 
*********************************************************************/

#ifndef GETINPUT_HPP
#define GETINPUT_HPP

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

#endif
