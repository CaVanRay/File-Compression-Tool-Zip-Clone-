/**********************************************************************************************************************
Title: Binary Handler
Author: Cavan Ray Theiss
Date: 10/14/2026
Description/Purpose:

Functions for getting the binary code and frequency maps of files to compress/decompress

**********************************************************************************************************************/

#include "cronchHeaders.h"

//**********************************************************************************************************************
// Reads the file as Binary into a vector of digits
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

    // Resize vector to fit file content
    std::vector<uint8_t> buffer(static_cast<size_t>(size));

    // Read entire file into buffer
    if (file.read(reinterpret_cast<char*>(buffer.data()), size){
        return buffer;
    } else {
        throw std::runtime_error("Failed to read file: " + filename);
    }
}

//**********************************************************************************************************************
// counts the number of times each byte appears throughout the whole file
//**********************************************************************************************************************

void byteFrequencyCounter(const std::vector<uint8_t>& data, uint32_t freq[256]){
    std::memset(freq, 0, sizeof(uint32_t) * 256);
    for (uint8_t byte : data){
        ++freq[byte];
    }
}

//**********************************************************************************************************************