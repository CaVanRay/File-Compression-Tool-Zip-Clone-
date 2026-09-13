# File-Compression-Tool-Zip-Clone-
## A tool for taking big files and making them smaller for easier transfer/transport
***

I looked up some info on "building your first real compressor" and I think I found a good guide for feeling the process out

## Start: Huffman Coding (your first real compressor)

1. Read the file into a std::vector<uint8_t> using std::ifstream in binary mode.
2. Count byte frequencies — a uint32_t freq[256] array. 
