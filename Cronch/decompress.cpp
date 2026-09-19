#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------- Tree node (same struct you used to build) ---------- */

typedef struct Node {
    uint8_t byte;        /* valid only for leaves */
    uint32_t freq;
}
