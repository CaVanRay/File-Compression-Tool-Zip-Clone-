#include <queue>
#include <memory>
#include <cstdint>
#include <cstring>

struct HuffmanNode {

uint32_t freq;
uint8_t symbol;  // valid only for leaves
bool is_leaf;
std::unique_ptr<HuffmanNode> left;
std::unique_ptr<HuffmanNode> right;

HuffmanNode(uint32_t f, uint8_t s) : freq(f), symbol(s), is_leaf(true) {}
HuffmanNode(uint32_t f, std::unique_ptr<HuffmanNode> l, std::unique_ptr<HuffmanNode> r) : freq(f), symbol(0), is_leaf(false), left(std::move(l)), right(std::move(r)) {}

};
