/**********************************************************************************************************************
Title: Huffman Tree Structs
Author: Cavan Ray Theiss
Date: 10/1/2026
Description/Purpose:

all of the structs and classes for building a Huffman tree

***********************************************************************************************************************/

#include "cronchHeaders.h"

struct HuffmanNode {

    uint32_t freq;
    uint8_t symbol; // Valid only for leaves
    bool is_leaf;
    std::unique_ptr<HuffmanNode> left;

}
