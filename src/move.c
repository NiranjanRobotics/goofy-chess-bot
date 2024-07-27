#include "move.h"

#define START_SQUARE_MASK 0b0000000000111111
#define END_SQUARE_MASK 0b0000111111000000
#define MOVE_FLAG_MASK 0b1111000000000000

Move
move_new(const Square start_square, const Square end_square, const MoveFlag flag)
{
    Move move = start_square | (end_square << 6) | (flag << 12);
    return move;
}

Square
start_square(const Move move)
{
    return move & START_SQUARE_MASK;
}

Square
end_square(const Move move)
{
    return (move & END_SQUARE_MASK) >> 6;
}

MoveFlag
move_flag(const Move move)
{
    return (move & MOVE_FLAG_MASK) >> 12;
}
