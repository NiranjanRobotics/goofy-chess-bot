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
piece_idx(const Side side, const PieceType piece_type)
{
    return ((side == WHITE) ? 0 : 6) + piece_type;
}

Bitboard
piece_board(const Board *const board, const Side side, const PieceType piece_type)
{
    return board->piece_boards[piece_idx(side, piece_type)];
}

Piece
piece_list_item(const Board *const board, const Side side, const PieceType piece_type)
{
    return board->piece_list[piece_idx(side, piece_type)];
}

// Bitboard for white pieces
Bitboard
white_pieces(const Board *const board)
{
    return piece_board(board, WHITE, PAWN)
         | piece_board(board, WHITE, KNIGHT)
         | piece_board(board, WHITE, BISHOP)
         | piece_board(board, WHITE, ROOK)
         | piece_board(board, WHITE, QUEEN)
         | piece_board(board, WHITE, KING);
}

// Bitboard for black pieces
Bitboard
black_pieces(const Board *const board)
{
    return piece_board(board, BLACK, PAWN)
         | piece_board(board, BLACK, KNIGHT)
         | piece_board(board, BLACK, BISHOP)
         | piece_board(board, BLACK, ROOK)
         | piece_board(board, BLACK, QUEEN)
         | piece_board(board, BLACK, KING);
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
