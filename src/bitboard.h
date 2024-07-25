#ifndef bitboard_h
#define bitboard_h

#include "common.h"

enum {
    ALL_SQUARES = 0xFFFFFFFFFFFFFFFFull,

    FILE_A = 0x8080808080808080ull,
    FILE_B = 0x4040404040404040ull,
    FILE_C = 0x2020202020202020ull,
    FILE_D = 0x1010101010101010ull,
    FILE_E = 0x0808080808080808ull,
    FILE_F = 0x0404040404040404ull,
    FILE_G = 0x0202020202020202ull,
    FILE_H = 0x0101010101010101ull,

    RANK_1 = 0x00000000000000FFull,
    RANK_2 = 0x000000000000FF00ull,
    RANK_3 = 0x0000000000FF0000ull,
    RANK_4 = 0x00000000FF000000ull,
    RANK_5 = 0x000000FF00000000ull,
    RANK_6 = 0x0000FF0000000000ull,
    RANK_7 = 0x00FF000000000000ull,
    RANK_8 = 0xFF00000000000000ull,

    LIGHT_SQUARES = 0x55AA55AA55AA55AAull,
    DARK_SQUARES = ~LIGHT_SQUARES,
};

#endif
