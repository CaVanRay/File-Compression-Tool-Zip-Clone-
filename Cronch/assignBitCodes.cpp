#include <string>
#include <vector>
#include <cstdint>
#include <memory>

// Code table: index = byte value, value = bit string
struct CodeTable {
    std::string code[256]; // e.g. code[72] = "010"
    uint8_t     len[256]; // code length in bits (0 if unused)
};

void assign_codes(const HuffmanNode* node, const std::string& prefix, CodeTable& table){
    if (!node) return;

    if (node->is_leaf) {
        table.code[node->symbol] = prefix;
        table.len[node->symbol] = static_cast<uint8_t>(prefix.size());
        return;
    }
}
