// Simple approach: write 256 bytes of code lengths, the bitstream
void write_header(std::ofstream& file, const CodeTable& table) {
    // 256 bytes, one per symbol: the code length in bits
    // (0 means the symbol never appeared)
    for (int i = 0; i < 256; i++)
        
}
