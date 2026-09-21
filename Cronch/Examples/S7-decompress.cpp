#include "cronchHeaders.h"

/* ---------- Tree node (same struct you used to build) ---------- */

typedef struct Node {
    uint8_t byte;        /* valid only for leaves */
    uint32_t freq;
    struct Node *left, *right;
} Node;

/* ---------- Rebuild tree from freq[] (same as encode side) ---------- */

Node* build_tree(const uint32_t freq[256]) {
    /* ... your existing priority-queue / two-queue build ... */
}

/* ---------- Bit reader (MSB-first) ---------- */
typedef struct {
    const uint8_t *data;
    size_t         len;
    size_t         pos;        /* bit position */
}  BitReader;

static inline int read_bit(BitReader *br) {
    if (br->pos >= br->len * 8) return 0;  /* padding */
    size_t byte_idx = br->pos >> 3;
    int    bit_idx  = 7 - (br->pos & 7);
    br->pos++;
    return (br->data[byte_idx] >> bit_idx) & 1;
}

/* ---------- Decompress ---------- */
int huffman_decompress(const uint8_t *compressed, size_t comp_len,
                       uint8_t *out, size_t out_cap)
{
    /* 1. Parse header */
    if (comp_len < 8 + 256 * 4) return -1;
    uint64_t orig_size;
    memcpy(&orig_size, compressed, 8);
    if (orig_size > out_cap) return -1;

    uint32_t freq[256];
    memcpy(freq, compressed + 8, 256 * 4);

    /* 2. Rebuild tree */
    Node *root = build_tree(freq);
    if (!root) return -1;

    /* 3. Walk tree, one bit at a time */
    BitReader br = { compressed + 8 + 256 * 4,
                     comp_len - 8 - 256 * 4, 0 };

    size_t written = 0;
    Node *cur = root;
    while (written < orig_size) {
        cur = read_bit(&br) ? cur->right : cur->left;
        if (!cur) { written++; break; }  /* EOF sentinel leaf */
        if (!cur->left && !cur->right) { /* leaf */
            out[written++] = cur->byte;
            cur = root;
        }
    }

    /* free tree */
    /* ... recursive free ... */
    return (int)written;
}
