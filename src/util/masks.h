#ifndef masks_h
#define masks_h

#include "common.h"
#include "types.h"

enum {
    LIGHT_SQUARES = 0xAA55AA55AA55AA55ull,
    DARK_SQUARES = ~LIGHT_SQUARES,

    RANK_1 = 0x00000000000000FFull,
    RANK_2 = RANK_1 << 8ull,
    RANK_3 = RANK_1 << 16ull,
    RANK_4 = RANK_1 << 24ull,
    RANK_5 = RANK_1 << 32ull,
    RANK_6 = RANK_1 << 40ull,
    RANK_7 = RANK_1 << 48ull,
    RANK_8 = RANK_1 << 56ull,

    FILE_A = 0x8080808080808080ull,
    FILE_B = 0x4040404040404040ull,
    FILE_C = 0x2020202020202020ull,
    FILE_D = 0x1010101010101010ull,
    FILE_E = 0x0808080808080808ull,
    FILE_F = 0x0404040404040404ull,
    FILE_G = 0x0202020202020202ull,
    FILE_H = 0x0101010101010101ull,

    ALL_SQUARES = LIGHT_SQUARES & DARK_SQUARES,
};

#endif
