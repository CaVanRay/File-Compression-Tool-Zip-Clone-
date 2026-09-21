#include "cronchHeaders.h"

void count_frequencies(const std::vector<uint8_t>& data, uint32_t freq[256]) {
    std::memset(freq, 0, sizeof(uint32_t) * 256);
    for (uint8_t byte : data) {
        ++freq[byte];
    }
}
