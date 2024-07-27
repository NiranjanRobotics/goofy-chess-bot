#include "bitboard.h"

Bitboard
square_board(Square square)
{
    return (0x8000000000000000ull >> square);
}
