#include "debug.h"

// Code that is actually run, currently used for debugging purposes
int
main(int argc, char *argv[])
{
    Board *board = safe_malloc(sizeof(Board)); // from util.h
    init_board(board, STARTING_POSITION, STARTING_STATE);
    print_board_info(board);
    free_board(board);

    print_move_info(move_new(E2, E4, EN_PASSANT_FLAG));

    printf("[Population of bitboard] %d\n", population_count(WK_START));

    return 0;
}
