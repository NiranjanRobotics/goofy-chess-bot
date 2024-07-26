#ifndef debug_h
#define debug_h

#include "util/common.h"
#include "util/masks.h"
#include "util/types.h"
#include "board.h"
#include "move.h"

void
print_bitboard(Bitboard bitboard);

void
print_move_info(Move move);

#endif
