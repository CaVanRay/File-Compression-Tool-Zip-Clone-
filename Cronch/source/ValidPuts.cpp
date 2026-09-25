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
/*
  3 types of getString: 
      getStringP : one with a prompt & error message
      getString  : one with just an error message
      getStringS : one with nothing (Silent collector)
*/

// PROMPT & ERROR
std::string getStringP(const std::string& prompt){
  std::string StringInput;
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

// JUST ERROR
std::string getString(){
  std::string StringInput;
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

// SILENT COLLECTOR
std::string getStringS(){
  std::string StringInput;
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

//**********************************************************************************************************************
/*
  3 types of getInt: 
      getIntP : one with a prompt & error message
      getInt  : one with just an error message
      getIntS : one with nothing (Silent collector)
*/

// PROMPT & ERROR
int getIntP(const std::string& prompt){
  
}

// JUST ERROR
int getInt(){
  
}

// SILENT COLLECTOR
int getIntS(){
  
}

//**********************************************************************************************************************
/*
  3 types of getDouble: 
      getDoubleP : one with a prompt & error message
      getDouble  : one with just an error message
      getDoubleS : one with nothing (Silent collector)
*/
