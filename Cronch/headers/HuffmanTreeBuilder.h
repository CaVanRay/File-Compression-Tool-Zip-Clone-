#pragma once

//*************************************************************

/* 

Just trying to think this through for a moment.

The data would come through as a list pair of bytes and a count of how often they appear
 - the "frequency map"

 Note: whether compiling or decompiling, a huffman tree will be built

I would need to track:

list of numbers to combine
prev & next connections
whether the prev is left or right
assigned bit code

*/