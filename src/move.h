#ifndef move_c
#define move_c

#include "common.h"
#include "types.h"

typedef unsigned short Move;

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

Square start_square(Move move);
Square end_square(Move move);
MoveFlag move_flag(Move move);

#endif
