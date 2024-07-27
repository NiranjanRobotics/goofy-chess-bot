# BOTez Gambit
A (future) UCI chess engine for InnovateX hackathon by Niranjan, Zach, and Daniel.

## Running the engine
Compilation:  `cd src`  and then  `gcc -g *.c util/*.c`  or  `clang -g *.c util/*.c` \
Debugger:  `gdb ./a.out`  or  `clang ./a.out` \
(if the output file from compilation is `./a.out`)

## Todo
- (This could be done at anytime in the process) Add FEN and PGN support
- Add board evaluation script
  - Use piece-square tables
  - Potentially track game phase, extra value for passed pawns in endgame
- Add functionality to Board struct
  - Add move to board
  - Update bitboards after move
  - Add zobrists
- Add legal move generation
  - Implement magic bitboards
- Use minimax algorithm and alpha-beta pruning to search move trees
- Add UCI support
- (Potentially) Add Opening Book
- (Potentially) Add NNUE trained on SF eval
