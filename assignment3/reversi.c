#include <stdio.h>
#include <stdlib.h>
#include "reversi.h"

void allocateReversiBoard(reversi_board *board) {
  int size = (*board).size;

  (*board).pieces = (reversi_space**) malloc(size * sizeof(reversi_space*));
  for (int i = 0; i < size; i++) {
    (*board).pieces[i] = (reversi_space*) malloc(size * sizeof(reversi_space));
    for (int j = 0; j < size; j++) {
      (*board).pieces[i][j].currentColor = emptySpace;
    }
  }
}

void printReversiBoard(reversi_board *board) {
  int size = (*board).size;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%d ", (*board).pieces[i][j].currentColor);
    }
    printf("\n");
  }
}

int isValidMove(reversi_board *board, int posX, int posY) {
  int size = (*board).size;

  if ()
  return 0;
}

int checkPath(reversi_board *board, int posX, int posY) {


  return 0;
}

int validMovesRemaining(reversi_board *board) {


  return 1;
}

void freeReversiBoard(reversi_board *board) {
  int size = (*board).size;

  for (int i = 0; i < size; i++) {
    free((*board).pieces[i]);
  }
  free((*board).pieces);
}
