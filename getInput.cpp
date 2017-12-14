/*********************************************************************
** Program name: getInput.cpp
** Author: Jesse McKenna
** Date: 9/27/2017
** Description: Helper functions for input validation 
*********************************************************************/

#include <iostream>
#include <string>
#include <cctype>
#include "getInput.hpp"

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
