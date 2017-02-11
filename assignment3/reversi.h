#ifndef REVERSI_H_
#define REVERSI_H_

enum {
  emptySpace = 0,
  whiteSpace = 1,
  blackSpace = 2
};

typedef struct {
  int currentColor;
} reversi_space;

typedef struct {
  reversi_space **pieces;
  int size;
} reversi_board;

/* Allocate memory for reversi board */
void allocateReversiBoard(reversi_board *board);

/* Print reversi board */
void printReversiBoard(reversi_board *board);

/* Check if the coordinates are a valid move. Return 1 for true, 0 for false */
int isValidMove(reversi_board *board, int playerColor, int posI, int posJ);

/* Check path for validity to confirm valid move. Return 1 for true, 0 for false */
int checkPath(reversi_board *board, int playerColor, int posI, int offsetI, int posJ, int offsetJ);

/* Check for remaining valid moves. Return 1 for true, 0 for false */
int validMovesRemaining(reversi_board *board, int playerColor);

/* Free memory for reversi board */
void freeReversiBoard(reversi_board *board);

#endif /* REVERSI_H_ */
