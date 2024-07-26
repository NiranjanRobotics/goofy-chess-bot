#include "board.h"

void
init_board(Board *const board)
{
    board->halfmoves = malloc(sizeof(Move) * 2);
    board->halfmove_counter = 0;

    board->piece_boards[0] = WP_START;
    board->piece_boards[1] = WN_START;
    board->piece_boards[2] = WB_START;
    board->piece_boards[3] = WR_START;
    board->piece_boards[4] = WQ_START;
    board->piece_boards[5] = WK_START;

    board->piece_boards[6] = BP_START;
    board->piece_boards[7] = BN_START;
    board->piece_boards[8] = BB_START;
    board->piece_boards[9] = BR_START;
    board->piece_boards[10] = BQ_START;
    board->piece_boards[11] = BK_START;
}

int
piece_board(const Side side, const PieceType piece_type)
{
    return (side == WHITE) ? 0 : 6 + piece_type;
}

Bitboard
white_pieces(const Board *const board)
{
    return board->piece_boards[piece_board(WHITE, PAWN)]
         | board->piece_boards[piece_board(WHITE, KNIGHT)]
         | board->piece_boards[piece_board(WHITE, BISHOP)]
         | board->piece_boards[piece_board(WHITE, ROOK)]
         | board->piece_boards[piece_board(WHITE, QUEEN)]
         | board->piece_boards[piece_board(WHITE, KING)];
}

Bitboard
black_pieces(const Board *const board)
{
    return board->piece_boards[piece_board(BLACK, PAWN)]
         | board->piece_boards[piece_board(BLACK, KNIGHT)]
         | board->piece_boards[piece_board(BLACK, BISHOP)]
         | board->piece_boards[piece_board(BLACK, ROOK)]
         | board->piece_boards[piece_board(BLACK, QUEEN)]
         | board->piece_boards[piece_board(BLACK, KING)];
}

Bitboard
all_pieces(const Board *const board)
{
    return white_pieces(board) | black_pieces(board);
}

void
play_move(Board *const board, Move move)
{
    Square starting_square = start_square(move);
    Square ending_square = end_square(move);
    // TODO: Add bitboard updates
}
