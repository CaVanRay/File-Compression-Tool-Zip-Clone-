/**********************************************************************************************************************
Title: Binary Handler
Author: Cavan Ray Theiss
Date: 09/29/2026
Description/Purpose:

Keeping this one off on its own for now. I wanna keep it clean and simple while I work my way through it.

the Binary Handler file is a collection of functions for collecting, organizing, and manipulating binary 
form data

**********************************************************************************************************************/

#include "cronchHeaders.h"

//**********************************************************************************************************************
// File Handler/Reader
//**********************************************************************************************************************

std::vector<uint8_t> readFileAsBinary(const std::string& filename){
    
    // Open file in binary mode
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    
    // Check if file failed to opened
    if (!file.is_open()){
        throw std::runtime_error("Failed to open file: " + filename);
    }

    // Get file size
    std::streamsize size + file.tellg();
    file.seekg(0, std::ios::beg);
}

//**********************************************************************************************************************
// Organizer/Counter
//**********************************************************************************************************************

byteFrequencyCounter(){
  
}

//**********************************************************************************************************************
// 
//**********************************************************************************************************************
