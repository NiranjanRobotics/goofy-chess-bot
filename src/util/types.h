#ifndef types_h
#define types_h

// Type definitions that are used throughout the project

#include "common.h"

// 64 bit representation of chessboard
typedef uint64_t Bitboard;

// Useful for using square names instead of numbers
typedef enum
{
    A8, B8, C8, D8, E8, F8, G8, H8,
    A7, B7, C7, D7, E7, F7, G7, H7,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A1, B1, C1, D1, E1, F1, G1, H1,
    SQUARE_NIL,
} Square;

// Enum for piece types
typedef enum
{
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING,
    PIECE_NIL,
} PieceType;

// Enum for sides
typedef enum
{
    WHITE,
    BLACK,
    SIDE_NIL,
} Side;

// Enum for castling rights to be used with castling rights array in GameState struct
typedef enum
{
    WHITE_CR_K,
    WHITE_CR_Q,
    BLACK_CR_K,
    BLACK_CR_Q,
} CastlingRights;

// Struct for piece list in board - shows piece's value and how many are on the board, as well as the squares they occupy
typedef struct
{
    PieceType type;
    int value, count;
    Side side;
} Piece;

/*
 * Game state that tracks en passant target (usually SQUARE_NIL), castling rights (kingside 
 * and queenside for both sides), counter for 50 move rule, and turn boolean for player turn
 */
typedef struct
{
    Square en_passant_target;
    bool castling_rights[4];
    int fifty_move_counter;
    bool white_turn;
} GameState;

#endif
