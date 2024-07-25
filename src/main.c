#include "common.h"
#include "bitboard.h"
#include "debug.h"

int main(int argc, char **argv)
{
    uint64_t bitboard = DARK_SQUARES;
    print_bitboard(bitboard);

    return 0;
}
