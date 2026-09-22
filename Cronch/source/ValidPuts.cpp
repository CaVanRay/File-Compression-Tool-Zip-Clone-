/*******************************************************************
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

*******************************************************************/

#include "cronchHeaders.h"

//******************************************************************
/*
  3 types of getString: 
      getStringP : one with a prompt & error message
*/
std::string getStringP(const std::string& prompt){
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
  std::cin.ignore(std::numeric_limitsa<std::streamsize>::max(), '\n');
}

std::string getString(){
  
}
