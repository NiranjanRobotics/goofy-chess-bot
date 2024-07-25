#include "common.h"
#include "bitboard.h"
#include "debug.h"

int main(int argc, char **argv)
{
    uint64_t bitboard = mask_square(square_from(4, 3));
    print_bitboard(bitboard
                   | shift_NW(bitboard)
                   | shift_north(bitboard)
                   | shift_NE(bitboard)
                   | shift_east(bitboard)
                   | shift_SE(bitboard)
                   | shift_south(bitboard)
                   | shift_SW(bitboard)
                   | shift_west(bitboard)
                   );

    return 0;
}
