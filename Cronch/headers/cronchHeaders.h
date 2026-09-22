#ifndef CRONCH_HEADERS_H
#define CRONCH_HEADERS_H

//************************************************
// all of my combined headers are organized here
//************************************************

// included librarys:
#include <queue>
#include <memory>
#include <vector>
#include <fstream>
#include <cstdint>
#include <stdlib.h>
#include <cstring.h>

// custom header files:
#include "UsePuts.h"
#include "CronchCompile.h"
#include "CronchDeCompile.h"

//************************************************

// Clear screen function swap
inline void clearScreen() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

//************************************************
#endif //CRONCH_HEADERS_H
