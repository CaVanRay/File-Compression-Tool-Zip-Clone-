
class BitWriter {
    uint8_t cur = 0;
    int     bits = 0; // bits accumulated in cur (0-7)
    std::vector<uint8_t> out;
}
