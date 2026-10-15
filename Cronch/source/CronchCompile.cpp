/*******************************************************************
Title: CronchCompile
Author: Cavan Ray Theiss
Date: 09/22/2026
Description/Purpose:

Main file for compiling sequence/functions

*******************************************************************/

#include "cronchHeaders.h"

//******************************************************************

void CronchCompile(){

    // 1. First get file to compile from user
    // 2. creat a vector set it to = readFileAsBinary(file)
    // 3. send vector to byteFrequencyCounter() along with an array 
    //    of frequencies
    // 4. Use the vector of bytes with matching array of frequencies
    //    to build a huffman tree 
    // 5. take the smallest 2 frequencies, make a node for each, with
    //    the smaller number (if not tied) marked "left" and the other 
    //    marked "right"
    // 6. remove these numbers from the list of frequencies but add 
    //    their sum
    // 7. repeat steps 5 & 6 until all numbers are added together
    // 8. using pointers traverse the tree from the sum to each byte 
    //    tracking how many lefts and rights it takes
    //    each left is '0' and each right is '1', the path combined
    //    creates the items ID number
    // 9. using each bytes ID number create a copy of the original
    //    vector but replace each byte with its ID number

}
