# File-Compression-Tool-Zip-Clone-
## A tool for taking big files and making them smaller for easier transfer/transport
***

I looked up some info on "building your first real compressor" and I think I found a good guide for feeling the process out

## Start: Huffman Coding (your first real compressor)

1. Read the file into a std::vector<uint8_t> using std::ifstream in binary mode.

2. Count byte frequencies — a uint32_t freq[256] array.

3. Build the Huffman tree — a min-heap (use std::priority_queue) of nodes, each with a frequency and left/right children. Pop two smallest, merge, push back. Repeat until one root remains.

4. Assign bit codes — walk the tree: left = 0, right = 1. Each leaf gets a variable-length code (frequent bytes get short codes like 01, rare bytes get long ones like 110101).

5. Encode — for each input byte, append its bit code to a bit buffer.  You need a bit writer that accumulates bits and flushes them into bytes:

```
class BitWriter {
    uint32_t buffer = 0;
    int bitCount = 0;
    std::vector<uint8_t> output;
public:
    void writeBits(uint32_t value, int numBits) {
        buffer |= value << bitCount;
        bitCount += numBits;
        while (bitCount >= 8) {
            output.push_back(buffer & 0xFF);
            buffer >>= 8;
            bitCount -= 8;
        }
    }
    void flush() {
        if (bitCount > 0) output.push_back(buffer & ((1 << bitCount) - 1));
    }
};
```
6. Write the header — you must serialize the Huffman tree (or the code lengths) into the output file so the decompressor can rebuild it.  A common trick: store the code length for each of the 256 byte values (a 256-byte table, or compress that table itself).

7. Decompress — read the header, rebuild the tree, then read bits one at a time walking the tree until you hit a leaf → emit that byte.

8. This alone will meaningfully compress text files. You now have a working compressor/decompressor pair.

***

## Level Up: LZ77 (sliding window)
Huffman handles frequency skew but not repeated sequences. LZ77 handles that:

- Maintain a sliding window of the last N bytes (e.g., 4096) of already-compressed output. 
- At each position, search the window for the longest match with the upcoming input. 
- If a match of length ≥ 3 is found, emit a back-reference: (offset, length) — "go back offset bytes and copy length bytes."
- If no match, emit a literal byte.

The output is a stream of tokens: either a literal byte or a (distance, length) pair. You encode these with a 1-bit flag:

- 0 + 8 bits → literal



