#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

}
