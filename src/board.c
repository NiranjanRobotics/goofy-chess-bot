#include "board.h"

// Initialize board pointer values
void
init_board(Board *const board, const Bitboard piece_boards[12], const GameState state)
{
    int piece_values[] = {100, 300, 320, 500, 900, 10000};
    board->halfmoves = safe_malloc(sizeof(Move) * 4);
    board->halfmove_counter = 0;

    for (int i = 0; i < 12; ++i)
    {
        board->piece_boards[i] = piece_boards[i];
        board->piece_list[i] = piece_from(
            i % 6,
            (i < 6) ? WHITE : BLACK,
            piece_values[i % 6],
            population_count(board->piece_boards[i])
        );
    }

    board->state = state;
}

// Free board pointer
void
free_board(Board *board)
{
    free(board->halfmoves);
    free(board);
}

// Get index of piece bitboard in board->piece_boards
int
piece_board(const Side side, const PieceType piece_type)
{
    return (side == WHITE) ? 0 : 6 + piece_type;
}

// Bitboard for white pieces
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

// Bitboard for black pieces
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

// Bitboard for all pieces
Bitboard
all_pieces(const Board *const board)
{
    return white_pieces(board) | black_pieces(board);
}

// Play move on the board
void
play_move(Board *const board, Move move)
{
    Square starting_square = start_square(move);
    Square ending_square = end_square(move);
    // TODO: Add bitboard updates
}
