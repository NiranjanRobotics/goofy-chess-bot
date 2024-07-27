#include "evaluation.h"

int
evaluate(const Board *const board)
{
    int material = evaluate_material(board);
    return material;
}

int
evaluate_material(const Board *const board)
{
    Piece piece_struct;
    PieceType piece;
    int material = 0;

    for (piece = PAWN; piece < PIECE_NIL; ++piece)
    {
        piece_struct = piece_list_item(board, WHITE, piece);
        material += piece_struct.count * piece_struct.value;
    }

    for (piece = PAWN; piece < PIECE_NIL; ++piece)
    {
        piece_struct = piece_list_item(board, BLACK, piece);
        material -= piece_struct.count * piece_struct.value;
    }

    return material;
}
