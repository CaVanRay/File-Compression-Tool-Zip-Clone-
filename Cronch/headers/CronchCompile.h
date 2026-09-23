#pragma once

// any functions required to compile declare here

std::vector<uint8_t> read_binary_file(const std::string& filename);

void count_frequencies(const std::vector<uint8_t>& data, uint32_t freq[256]);
