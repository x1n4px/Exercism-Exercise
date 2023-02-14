#include "grains.h"
/*
1 -> 1
2 -> 2
3 -> 4
4 -> 8
5 -> 16
6 -> 32
64 -> 128 -> 256 -> 512 -> 1024 -> 2048 -> 5096 -> 10192


1
1*2 = 2
*/


uint64_t square(uint8_t index) {
   if (index < 1 || index > 64) {
        return 0;
    }
    uint64_t grains = 1;
    for (int i = 2; i <= index; i++) {
        grains *= 2;
    }
    return grains;
}

uint64_t total(void) {
    uint64_t total_grains = 0;
    for (int i = 1; i <= 64; i++) {
        total_grains += square(i);
    }
    return total_grains;
}