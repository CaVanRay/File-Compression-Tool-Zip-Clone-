# File-Compression-Tool-Zip-Clone-
## A tool for taking big files and making them smaller for easier transfer/transport
***

I looked up some info on "building your first real compressor" and I think I found a good guide for feeling the process out

Currently have all the examples for the first section, next I need to work on using them to make a working version
of my own

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
- 1 + 15 bits (distance) + 8 bits (length) → back-reference 

The Code Review StackExchange LZ77 implementation is a clean, readable reference that does exactly this with a BitWriter/BitReader pair. 

***

## Combine: LZ77 + Huffman = Deflate

This is what ZIP/GZIP actually do. You take the LZ77 token stream (literals, length codes, distance codes) and Huffman-encode those tokens instead of raw bytes.  This gives you the compression ratios of real-world tools.

The key insight: you build two separate Huffman trees — one for literals/lengths, one for distances — because they have different frequency distributions. 

***

## Practical Tips

- Start with Huffman only. Get the bit I/O, tree building, and header serialization working.  This is the hardest part to get right (off-by-one bits, endianness, padding).
- Test round-trip early. Compress → decompress → compare byte-for-byte with the original. Do this after every change.
- Work in std::vector<uint8_t>, not std::string. Strings with null bytes are a pain.
- The bit-level I/O is where most bugs live. A BitReader that mirrors your BitWriter (reads from MSB first, same order) will save you hours.
- Shannon entropy is your hard floor.  For a file, compute H = -Σ p(x)·log₂(p(x)) over byte frequencies. Your compressed size can't go below H × N / 8 bytes. Use this to verify you're not doing something wrong.

The ochagavia.nl "Let's build a compressor from scratch" writeup walks through the Huffman approach step by step and is a good companion to follow alongside your own implementation. 
