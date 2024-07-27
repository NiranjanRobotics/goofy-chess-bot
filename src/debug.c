#include "debug.h"
#include "move.h"
#include "util/types.h"

// Print info for board struct as well as gui-like board position
void
print_board_info(const Board *const board)
{
    uint64_t bit, bitboard;
    int board_position[64];

    for (int i = 0; i < 64; ++i)
        board_position[i] = 0;

    /*
      . : empty tile
      P/p : pawn
      N/n : knight
      B/b : bishop
      R/r : rook
      Q/q : queen
      K/k : king
    */
    const char chess_chars[] = ".PNBRQKpnbrqk";

    for (int i = 0; i < 12; ++i)
    {
        bitboard = board->piece_boards[i];

        for (int j = 0; j < 64; ++j)
        {
            bit = (bitboard >> j) & 1;
            if (bit != 0) board_position[j] = i + 1;
        }
    }

    printf("<Board [Position:\n");

    for (int i = 63; i >= 0; --i)
    {
        if ((i & 7) == 7) printf("%d | ", (i >> 3) + 1);
        printf("%c ", chess_chars[board_position[i]]);
        if ((i & 7) == 0) printf("\n");
    }

    printf("    ----------------\n");
    printf("    a b c d e f g h \n]");

    printf(" [State: <State [Turn: %s] [Castling: %c%c%c%c]>]",
           (board->state.white_turn)? "White" : "Black",
           (board->state.castling_rights[WHITE_CR_K])? 'K' : '\0',
           (board->state.castling_rights[WHITE_CR_Q])? 'Q' : '\0',
           (board->state.castling_rights[BLACK_CR_K])? 'k' : '\0',
           (board->state.castling_rights[BLACK_CR_Q])? 'q' : '\0');

    printf(">\n");
}

// Print a bitboard in a human-readable and visual format
void
print_bitboard(const Bitboard bitboard)
{
    printf("<Bitboard [\n");

    uint64_t bit;
    for (int i = 63; i >= 0; --i)
    {
        bit = (bitboard >> i) & 1;

        if (bit == 0) printf(". ");
        else printf("x ");
        if ((i & 7) == 0) printf("\n");
    }

    printf("]>\n");
}

// Print info for Move type
void
print_move_info(const Move move)
{
    char files[] = "abcdef";

    Square starting_square = start_square(move),
           ending_square = end_square(move);

    char *flag;
    switch (move_flag(move))
    {
        case PAWN_2MOVE_FLAG:
            flag = "Pawn 2 moves";
            break;

        case EN_PASSANT_FLAG:
            flag = "En passant";
            break;

        case CASTLE_FLAG:
            flag = "Castle";
            break;

        case PROMOTE_QUEEN_FLAG:
            flag = "Promote queen";
            break;

        case PROMOTE_ROOK_FLAG:
            flag = "Promote rook";
            break;

        case PROMOTE_BISHOP_FLAG:
            flag = "Promote bishop";
            break;

        case PROMOTE_KNIGHT_FLAG:
            flag = "Promote knight";
            break;

        case FLAG_NIL:
            flag = "None";
    }

    printf("<Move [Start square: %c%d] ", files[starting_square & 7], (8 - (starting_square >> 3)));
    printf("[End square: %c%d] ", files[ending_square & 7], (8 - (ending_square >> 3)));
    printf("[Flag: %s]>\n", flag);
}
