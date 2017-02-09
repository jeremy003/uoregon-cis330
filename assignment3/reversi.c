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

  (*board).pieces[size / 2][size / 2].currentColor = whiteSpace;
  (*board).pieces[(size / 2) - 1][size / 2].currentColor = blackSpace;
  (*board).pieces[(size / 2) - 1][(size / 2) - 1].currentColor = whiteSpace;
  (*board).pieces[size / 2][(size / 2) - 1].currentColor = blackSpace;
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

int isValidMove(reversi_board *board, int posI, int posJ) {
  int size = (*board).size, offsetI = 0, offsetJ = 0;

  if ((*board).pieces[posI][posJ].currentColor != emptySpace) {
    return 0;
  }
  // The selected point is empty, so check the 3 x 3 matrix around it
  for (int i = posI - 1; i <= posI + 1; i++) {
    if (i < size && i >= 0) {
      for (int j = posJ - 1; j <= posJ + 1; j++) {
        if (j < size && j >= 0) {
          if ((*board).pieces[i][j].currentColor != emptySpace) {
            offsetI = i - posI;
            offsetJ = j - posJ;
            if (checkPath(board, i, offsetI, j, offsetJ) == 1) {
              printf("path is valid\n");
            }
          }
        }
      }
    }
  }

  return 0;
}

int checkPath(reversi_board *board, int posI, int offsetI, int posJ, int offsetJ) {
  int comparisonColor = (*board).pieces[posI][posJ].currentColor, size = (*board).size, i = posI + offsetI, j = posJ + offsetJ;
  while ((i < size && i >= 0) && (j < size && j >= 0)) {
    if ((*board).pieces[i][j].currentColor != comparisonColor && (*board).pieces[i][j].currentColor != 0) {
      return 1;
    }
    i += offsetI;
    j += offsetJ;
  }

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
