#include <queue>
#include <memory>
#include <cstdint>
#include <cstring>

struct HuffmanNode {

uint32_t freq;
uint8_t symbol;  // valid only for leaves
bool is_leaf;
std::unique_ptr<HuffmanNode> left;

};
