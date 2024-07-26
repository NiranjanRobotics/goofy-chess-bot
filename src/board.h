#ifndef board_h
#define board_h

#include "util/common.h"
#include "util/types.h"

typedef struct
{
    Square en_passant_target;
    bool white_castling, black_castling;
    int fifty_move_counter;
    bool white_turn;
} GameState;

typedef struct
{
    Bitboard piece_boards[12];
    Piece piece_list[12];
    GameState state;
} Board;

Bitboard white_pieces(const Board *const board);
Bitboard black_pieces(const Board *const board);
Bitboard all_pieces(const Board *const board);
Bitboard piece_bitboard(const Board *const board, const Side side, const PieceType piece_type);
void play_move(const Board *const board/*, Move move */);

#endif
