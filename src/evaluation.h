#ifndef evaluation_h
#define evaluation_h

#include "util/common.h"
#include "util/types.h"
#include "util/masks.h"
#include "board.h"
#include "move.h"

int evaluate(const Board *const board);
int evaluate_material(const Board *const board);
int evaluate_pawns(const Board *const board);
int evaluate_mobility(const Board *const board); // TODO: Add this after adding legal move generation
int evaluate_king(const Board *const board);

#endif
