#ifndef board_h
#define board_h

#include "util/common.h"
#include "util/types.h"
#include "util/masks.h"
#include "util/util.h"
#include "move.h"

typedef struct
{
    Bitboard piece_boards[12];
    Piece piece_list[12];
    Move *halfmoves;
    int halfmove_counter;
    GameState state;
} Board;

void
init_board(Board *const board, const Bitboard piece_boards[12], const GameState state);

Bitboard
white_pieces(const Board *const board);

Bitboard
black_pieces(const Board *const board);

Bitboard
all_pieces(const Board *const board);

int
piece_board(const Side side, const PieceType piece_type);

void
play_move(Board *const board, Move move);

void
free_board(Board *board);

#endif
