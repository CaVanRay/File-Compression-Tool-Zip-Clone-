
// Simple approach: write 256 bytes of code lengths, the bitstream

void write_header(std::ofstream& file, const CodeTable& table) {
    // 256 bytes, one per symbol: the code length in bits
    // (0 means the symbol never appeared)
    for (int i = 0; i < 256; i++)
        file.put(static_cast<char>(table.len[i]));
}

//*********************************************************************************************************************

// Full file layout:

// [4 bytes: original message length in bits]
// [256 bytes: code lengths, one per sybol]
// [compressed bitstream]

void write_compressed(std::ofstream& file, const std::string& input, const CodeTable& table) {
    file.open("output.huf", std::ios::binary);

    // Header: original bit count (so decoder knows where to stop)
    uint32_t bit_count = static_cast<uint32_t>(input.size() * 8);
    file.write(reinterpret_cast<const char*>(&bit_count), 4);

    // 256 code-length bytes
    for (int i = 0; i < 256; i++)
        file.put(static_cast<char>(table.len[i]));

    // Compressed data
    auto compressed = huffman_encode(input, table);
    file.write(reinterpret_cast<const char*>(comopressed.data()), static_cast<std::streamsize>(compressed.size()));

    file.close();
}

//*********************************************************************************************************************

// Decoder side - rebuild the tree from code lengths:

HuffmanNode* build_tree_from_lengths(const uint8_t lengths[256]) {
    // Count how many codes of each length exist
    int count[32] = {};  // max code length is 255, but 32 is plenty for practice
    for (int i = 0; i < 256; i++)
        count[lengths[i]]++;

    // Build tree bottom-up (like canonical Huffman)
    // ... or use the "walk the lengths" approach:
    // assign codes in order, build a trie as you go
    //
    // Simpler: just build a trie directly
    HuffmanNode root;
    root.is_leaf = false;
    root.left = root.right = nullptr;

    for (int sym = 0; sym < 256; sym++) {
        if (lengths[sym] == 0) continue;

        HuffmanNode* cur = &root;
        for (int bit = 0; bit < lengths[sym]; bit++) {
            // The bit value doesn't matter for building —
            // we just need to place leaves at the right depth.
            // For a canonical rebuild, assign codes in symbol order.
            // (See note below.)
        }
    }
    return &root;
}

//*********************************************************************************************************************

// Canonical trick (more robust): Instead of storing the actual bit strings, the decoder re-derives them from the lengths alone:

// Rebuild canonical codes from lengths
void build_canonical_codes(const uint8_t lengths[256], CodeTable& table) {
    // 1. Sort symbols by (length, symbol)
    std::vector<int> order(256);
    std::iota(order.begin(), order.end(), 0);
    std::sort(order.begin(), order.end(), [&](int a, int b) {
        if (lengths[a] != lengths[b]) return lengths[a] < lengths[b];
        return a < b;
    });

    // 2. Assign codes in order
    uint32_t code = 0;
    int prev_len = 0;
    for (int sym : order) {
        if (lengths[sym] == 0) continue;
        code <<= (lengths[sym] - prev_len);
        prev_len = lengths[sym];

        std::string s(lengths[sym], '0');
        for (int i = 0; i < lengths[sym]; i++)
            if (code & (1u << (lengths[sym] - 1 - i)))
                s[i] = '1';

        table.code[sym] = s;
        table.len[sym] = lengths[sym];
    }
}

//*********************************************************************************************************************

/*
NOTE:
This is the standard approach used by DEFLATE/PNG — the encoder and decoder both derive the same codes from just 
the length table, so you only need to store 256 bytes of lengths (plus the bit count). The encoder must also use 
canonical codes (or at least the decoder must use them consistently with what the encoder produced).

TL;DR: Store 256 length bytes + original bit count in the header. Decoder rebuilds the tree/codes from lengths 
alone. Total overhead: 260 bytes regardless of input size.
*/



