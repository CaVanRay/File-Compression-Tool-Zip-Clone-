
class BitWriter {
    uint8_t cur = 0;
    int     bits = 0; // bits accumulated in cur (0-7)
    std::vector<uint8_t> out;

public:
    void write(uint8_t bit) {
        cur = (cur << 1) | bit;
        if (++bits == 8) {
            out.push_back(cur);
            cur = 0;
            bits = 0;
        }
    }

    void write_code(const std::string& code) {
        for (char c : code)
            write(c - '0');
    }

    // Pad with zeros and flush any remaining bits
    void flush() {
        if (bits > 0) {
            cur <<= (8 - bits);
            out.push_back(cur);
        }
    }

}
