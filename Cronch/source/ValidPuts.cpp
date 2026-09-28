/**********************************************************************************************************************
Title: ValidPuts
Author: Cavan Ray Theiss
Date: 09/21/2026
Description/Purpose:

General use safety net functions that can be used to validate any
type of data input whether int, string, or whatever

I'll be implementing multiple options for each data type, so you
can just validate input or you can pair it with a message to the 
user

not all of these are going to be useful to Cronch, but I want this 
in my toolbox for future programs I write

**********************************************************************************************************************/

#include "cronchHeaders.h"

//**********************************************************************************************************************
// STRINGS
//**********************************************************************************************************************
/*
  3 types of getString: 
      getStringP : one with a prompt & error message
      getString  : one with just an error message
      getStringS : one with nothing (Silent collector)
*/

// PROMPT & ERROR
std::string getStringP(const std::string& prompt){
  // String to grab
  std::string StringInput;
  // Will continuously loop until break
  while (true) {
    std::cout << prompt;
    // Try reading a string
    if (std::getline(std::cin, StringInput)) {
      // on success, return value, breaking the loop
      return StringInput;
    }
    // if it reaches here that means input failed
    std::cout << "Input failure, please try again. \n";
    // clear input
    std::cin.clear();
    // also clear the input buffer after failed getline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}

// JUST ERROR
std::string getString(){
  std::string StringInput;
  // Will continuously loop until break
  while (true) {
    // Try reading a string
    if (std::getline(std::cin, StringInput)) {
      // on success, return value, breaking the loop
      return StringInput;
    }
    // if it reaches here that means input failed
    std::cout << "Input failure, please try again. \n";
    // clear input
    std::cin.clear();
    // also clear the input buffer after failed getline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}

// SILENT COLLECTOR
std::string getStringS(){
  std::string StringInput;
  // Will continously loop until break
  while (true) {
    // Try reading a string
    if (std::getline(std::cin, StringInput)) {
      // on success, return value, breaking the loop
      return StringInput;
    }
    // if it reaches here that means input failed
    // clear input
    std::cin.clear();
    // also clear the input buffer after failed getline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}

//**********************************************************************************************************************
// INTS
//**********************************************************************************************************************
/*
  3 types of getInt: 
      getIntP : one with a prompt & error message
      getInt  : one with just an error message
      getIntS : one with nothing (Silent collector)
*/

// PROMPT & ERROR
int getIntP(const std::string& prompt){
  // value to grab
  int intValue;
  // will continuously loop until break
  while(true){
    std::cout << prompt;
    // Try reading an int
    if (std::cin >> intValue) {
        // On success, return value, breaking the loop
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return intValue;
    }
    // If it reaches here that means input failed
    std::cout << "Invalid number. Please try again. \n";
    // Clear input
    std::cin.clear();
    // Throw away invalid characters
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  } 
}

// JUST ERROR
int getInt(){
  // Value to grab
  int intValue;
  // Will continuously loop until break
  while(true) {
      // Try reading an int
      if (std::cin >> intValue) {
          // on success, return value, breaking the loop
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          return intValue;
      }
      // if it reaches here that means input failed
      std::cout << "Invalid number. Please try again. \n";
      // clear input
      std::cin.clear();
      // Throw away invalid characters
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}

// SILENT COLLECTOR
int getIntS(){
  // value to grab
  int intValue;
  // will continuously loop until break
  while(true) {
      // Try reading an int
      if (std::cin >> intValue) {
          // On success, return value, breaking the loop
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          return intValue;
      }
      // if it reaches here that means input failed
      // Clear input
      std::cin.clear();
      // Throw away invalid characters
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}

//**********************************************************************************************************************
// DOUBLES
//**********************************************************************************************************************
/*
  3 types of getDouble: 
      getDoubleP : one with a prompt & error message
      getDouble  : one with just an error message
      getDoubleS : one with nothing (Silent collector)
*/

// PROMPT & ERROR
double getDoubleP(const std::string& prompt){
  // Value to grab
  double dValue;
  // Will continously loop until break
  while(true){
    std::cout << prompt;
    //Try reading a double
    if(std::cin >> dValue) {
      // On success, return value, breaking the loop
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return dValue;
    }
    // If it reaches here that means input failed
    std::cout << "Invalid number. Please try again. \n";
    // Clear input
    std::cin.clear();
    // Throw away invalid characters
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}

// JUST ERROR
double getDouble(){
  // Value to grab
  double dValue;
  // Will continously loop until break
  while (true) {
    // Try reading a double
    if(std::cin >> dValue) {
      // On success, return value, breaking the loop
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return dValue;
    }
    // If it reaches here that means input failed
    std::cout << "Invalid number. Please try again. \n";
    // Clear input
    std::cin.clear();
    // Throw away invalid characters
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}

// SILENT COLLECTOR
double getDoubleS(){
  // Value to grab
  double dValue;
  // Will continously loop until break
  while (true) {
    // Try reading a double 
    if(std::cin >> dValue) {
      // On success, return value, breaking the loop
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return dValue;
    }
    // If it reaches here that means input failed
    // Clear input
    std::cin.clear();
    //Throw away invalid characters
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}

//**********************************************************************************************************************
// BOOLS
//**********************************************************************************************************************
/*
  3 types of getYN: 
      getYNP : one with a prompt & error message
      getYN  : one with just an error message
      getYNS : one with nothing (Silent collector)
*/

// PROMPT & ERROR
bool getYNP(const std::string& prompt){
  // Value to grab
  std::string input;
  // Will continously loop until break
  while(true) {
    std::cout << prompt;
    std::getline(std::cin, input);
    if(input.length() == 1) {
      char c = std::tolower(input[0]);
      if (c == 'y')
        return true;
      if (c == 'n')
        return false;
    }
    std::cout << "Invalid input. Please type 'y' or 'n'. \n";
  }
}

// JUST ERROR
bool getYN(){
  // Value to grab
  std::string input;
  // Will continously loop until break
  while(true) {
    std::getline(std::cin, input);
    if(input.length() == 1) {
      char c = std::tolower(input[0]);
      if (c == 'y')
        return true;
      if (c == 'n')
        return false;
    }
    std::cout << "Invalid input. Please type 'y' or 'n'. \n";
  }
}

// SILENT COLLECTOR
bool getYNS(){
  // Value to grab
  std::string input;
  // Will continously loop until break
  while(true) {
    std::getline(std::cin, input);
    if(input.length() == 1) {
      char c = std::tolower(input[0]);
      if (c == 'y')
        return true;
      if (c == 'n')
        return false;
    }
  }
}
