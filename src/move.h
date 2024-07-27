#ifndef move_c
#define move_c

#include "util/common.h"
#include "util/types.h"

/*
 * Move type (first 6 bits are start square, next 6 are end square, then last 4 are flags)
 * Inspired by Sebastian Lague's move representation
 */
typedef unsigned short Move;

// Enum for move flags
typedef enum
{
    PAWN_2MOVE_FLAG = 0b0100,
    EN_PASSANT_FLAG = 0b0010,
    CASTLE_FLAG = 0b0001,

    PROMOTE_QUEEN_FLAG = 0b1000,
    PROMOTE_ROOK_FLAG = 0b1001,
    PROMOTE_BISHOP_FLAG = 0b1010,
    PROMOTE_KNIGHT_FLAG = 0b1011,

    FLAG_NIL = 0b0000,
} MoveFlag;

Move
move_new(const Square start_square, const Square end_square, const MoveFlag flag);

Square
start_square(const Move move);

Square
end_square(const Move move);

MoveFlag
move_flag(const Move move);

#endif
