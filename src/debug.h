#ifndef debug_h
#define debug_h

// Useful debugging and logging functions

#include "util/common.h"
#include "util/masks.h"
#include "util/types.h"
#include "board.h"
#include "move.h"

void
print_board_info(const Board *const board);

void
print_bitboard(const Bitboard bitboard);

void
print_move_info(const Move move);

#endif
