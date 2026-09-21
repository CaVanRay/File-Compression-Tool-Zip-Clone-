#ifndef CRONCH_HEADERS_H
#define CRONCH_HEADERS_H
//***********************************

#include <fstream>
#include <vector>
#include <cstdint>
#include <stdlib.h>
#include <cstring.h>
#include <vector>
#include <queue>
#include <memory>

//***********************************

// Clear screen function swap
inline void clearScreen() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

//***********************************
#endif //CRONCH_HEADERS_H
