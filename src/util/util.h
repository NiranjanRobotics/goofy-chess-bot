#ifndef util_h
#define util_h

#include "common.h"
#include "types.h"
#include "masks.h"

extern const Bitboard STARTING_POSITION[12];
extern const GameState STARTING_STATE;

int
population_count(const Bitboard board);

Piece
piece_from(const PieceType type, const Side side, const int value, const int count);

void *
safe_malloc(const size_t size);

#endif
