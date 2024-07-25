#include "bitboard.h"

const uint64_t ranks[8] = {RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8};
const uint64_t files[8] = {FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H};

inline int rank_of(int square)
{
    return square >> 3;
}

inline int file_of(int square)
{
    return square & 7;
}
