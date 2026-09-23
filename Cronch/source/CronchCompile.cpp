/*******************************************************************
Title: CronchCompile
Author: Cavan Ray Theiss
Date: 09/22/2026
Description/Purpose:

Main file for compiling sequence/functions

*******************************************************************/

#include "cronchHeaders.h"

//******************************************************************

std::vector<uint8_t> read_binary_file(const std::string& filename){

  // Open file in binary mode
  std::ifstream file(filename, std::ios::binary | std::ios::ate);

  if (!file.is_open()){
    throw std::runtime_error("Failed to open file: " + filename);
  }

  // Get file size
  std::streamsize size + file.tellg();
  file.seekg(0, std::ios::beg);

  // Resize vector tofit file content
}
