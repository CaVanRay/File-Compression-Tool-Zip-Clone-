
// Simple approach: write 256 bytes of code lengths, the bitstream

void write_header(std::ofstream& file, const CodeTable& table) {
    // 256 bytes, one per symbol: the code length in bits
    // (0 means the symbol never appeared)
    for (int i = 0; i < 256; i++)
        file.put(static_cast<char>(table.len[i]));
}

//***********************************************************************

// Full file layout:

// [4 bytes: original message length in bits]
// [256 bytes: code lengths, one per sybol]
// [compressed bitstream]

void write_compressed(std::ofstream& file, const std::string& input, const CodeTable& table) {
    
}
