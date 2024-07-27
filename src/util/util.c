#include "util.h"

const Bitboard STARTING_POSITION[12] = {
    0x000000000000FF00ull,
    0x0000000000000042ull,
    0x0000000000000024ull,
    0x0000000000000081ull,
    0x0000000000000010ull,
    0x0000000000000008ull,
    0x00FF000000000000ull,
    0x4200000000000000ull,
    0x2400000000000000ull,
    0x8100000000000000ull,
    0x1000000000000000ull,
    0x0800000000000000ull,
};

const GameState STARTING_STATE = {
    .en_passant_target = SQUARE_NIL,
    .white_turn = true,
    .fifty_move_counter = 0,
    .castling_rights = {true, true, true, true}
};

Piece
piece_from(const PieceType type, const Side side, const int value, const int count)
{
    return (Piece) {
        .type = type,
        .side = side,
        .value = value,
        .count = count,
    };
}

int
population_count(const Bitboard board)
{
    uint64_t count = board;
    count -= (count >> 1) & 0x5555555555555555ull;
    count = (count & 0x3333333333333333ull) + ((count >> 2) & 0x3333333333333333ull);
    count = (count + (count >> 4)) & 0x0F0F0F0F0F0F0F0Full;
    return (int) ((count * 0x0101010101010101ull) >> 56);
}

void *
safe_malloc(const size_t size)
{
    void *allocated = malloc(size);

    if (!allocated)
    {
        fprintf(stderr, "[ERROR] Failed to allocate %zu bytes safely.\n", size);
        exit(1);
    }

    return allocated;
}
