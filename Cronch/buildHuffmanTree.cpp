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

// Min-heap: compare by frequency (smaller = higher priority)
struct Compare {
  bool operator()(const std::unique_ptr<HuffmanNode>& a, const std::unique_ptr<HuffmanNode>& b) const {
      return a->freq > b->freq; // note: GREATER than -> min-heap
  }
};

std::unique_ptr<HuffmanNode> build_huffman_tree(const uint32_t freq[256]) {
    using PQ = std::priority_queue<
        std::unique_ptr<HuffmanNode>,
        std::vector<std::unique_ptr<HuffmanNode>>,
        Compare
    >;

  PQ pq;

  // Push leaves with non-zero frequency
  for (int i = 0; i < 256; ++i){
    
  }
  
}
