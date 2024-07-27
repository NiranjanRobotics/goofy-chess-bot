#include "debug.h"

// Code that is actually run, currently used for debugging purposes
int
main(int argc, char *argv[])
{
    Board *board = safe_malloc(sizeof(Board)); // from util.h
    init_board(board, STARTING_POSITION, STARTING_STATE);
    print_board_info(board);
    free_board(board);

    return 0;
}
