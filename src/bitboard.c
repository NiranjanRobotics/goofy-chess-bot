#include "bitboard.h"
#include <stdint.h>

const uint64_t ranks[8] = {RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8};
const uint64_t files[8] = {FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H};

int rank_of(int square)
{
    return square >> 3;
}

int file_of(int square)
{
    return square & 7;
}

int square_from(int file, int rank)
{
    return (rank << 3) | file;
}

uint64_t mask_rank(int square)
{
    return ranks[rank_of(square)];
}

uint64_t mask_file(int square)
{
    return files[file_of(square)];
}

uint64_t mask_square(int square)
{
    return mask_rank(square) & mask_file(square);
}

uint64_t shift_north(uint64_t square_mask)
{
    return square_mask << 8;
}

uint64_t shift_south(uint64_t square_mask)
{
    return square_mask >> 8;
}

uint64_t shift_east(uint64_t square_mask)
{
    return square_mask >> 1;
}

uint64_t shift_west(uint64_t square_mask)
{
    return square_mask << 1;
}

uint64_t shift_NE(uint64_t square_mask)
{
    return square_mask << 9;
}

uint64_t shift_NW(uint64_t square_mask)
{
    return square_mask << 7;
}

uint64_t shift_SE(uint64_t square_mask)
{
    return square_mask >> 9;
}

uint64_t shift_SW(uint64_t square_mask)
{
    return square_mask >> 7;
}
