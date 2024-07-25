#include "debug.h"

void print_bitboard(uint64_t bitboard)
{
    uint64_t bit;

    for (int i = 63; i >= 0; --i)
    {
        bit = (bitboard >> i) & 1;

        if (bit == 0) printf("• ");
        if (bit == 1) printf("■ ");

        if ((i & 7) == 0) printf("\n");
    }
}
