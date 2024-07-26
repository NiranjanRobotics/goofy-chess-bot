#include "debug.h"
#include "move.h"

void
print_bitboard(Bitboard bitboard)
{
    printf("<Bitboard> [[");

    uint64_t bit;
    for (int i = 63; i > 0; --i)
    {
        bit = (bitboard >> i) & 1;

        if (bit == 0) printf(". ");
        else printf("x ");
        if ((i & 7) == 0) printf("\n");
    }

    printf("]]");
}

void
print_move_info(Move move)
{
    char files[] = "abcdef";

    Square starting_square = start_square(move),
           ending_square = end_square(move);

    char *flag = malloc(sizeof(char) * 20);
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

    printf("<Move> [Start square: %c%d] ", files[starting_square & 7], (starting_square >> 3));
    printf("[End square: %c%d] ", files[ending_square & 7], (ending_square >> 3));
    printf("[Flag: \'%s\']", flag);

    free(flag);
}
