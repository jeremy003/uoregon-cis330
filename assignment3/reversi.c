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
  printf("  ");
  for (int i = 0; i < size; i++) {
    printf("%d ", i);
  }
  printf("\n");

  for (int i = 0; i < size; i++) {
    printf("%d ", i);
    for (int j = 0; j < size; j++) {
      printf("%d ", (*board).pieces[i][j].currentColor);
    }
    printf("\n");
  }
}

int isValidMove(reversi_board *board, int playerColor, int posI, int posJ) {
  int size = (*board).size, offsetI = 0, offsetJ = 0, valid = 0, enemyColor = 0;
  printf("checking validity. player color: %d\n", playerColor);

  if ((*board).pieces[posI][posJ].currentColor != emptySpace) {
    return 0;
  }

  if (playerColor == whiteSpace) {
    enemyColor = blackSpace;
  } else {
    enemyColor = whiteSpace;
  }

  // The selected point is empty, so check the 3 x 3 matrix around it
  for (int i = posI - 1; i <= posI + 1; i++) {
    if (i < size && i >= 0) {
      for (int j = posJ - 1; j <= posJ + 1; j++) {
        if (j < size && j >= 0) {
          if ((*board).pieces[i][j].currentColor == enemyColor) {
            offsetI = i - posI;
            offsetJ = j - posJ;
            if (checkPath(board, playerColor, i, offsetI, j, offsetJ) == 1) {
              valid = 1;
            }
          }
        }
      }
    }
  }

  return valid;
}

int checkPath(reversi_board *board, int playerColor, int posI, int offsetI, int posJ, int offsetJ) {
  int size = (*board).size, i = posI + offsetI, j = posJ + offsetJ, comparisonColor = 0;
  if (playerColor == whiteSpace) {
    comparisonColor = blackSpace;
  } else {
    comparisonColor = whiteSpace;
  }

  while ((i < size && i >= 0) && (j < size && j >= 0)) {
    if ((*board).pieces[i][j].currentColor == emptySpace) {
      return 0;
    }
    if ((*board).pieces[i][j].currentColor == playerColor) {
      // Flip pieces back to original point
      posI = posI - offsetI;
      posJ = posJ - offsetJ;
      while (i != posI || j != posJ) {
        (*board).pieces[i][j].currentColor = playerColor;
        i -= offsetI;
        j -= offsetJ;
      }
      (*board).pieces[i][j].currentColor = playerColor;
      return 1;
    }
    i += offsetI;
    j += offsetJ;
  }

  return 0;
}

int checkPathValidity(reversi_board *board, int playerColor, int posI, int offsetI, int posJ, int offsetJ) {
  // printf("check path true starting at i = %d, j = %d, i offset = %d, j offset = %d\n", posI, posJ, offsetI, offsetJ);

  int size = (*board).size, i = posI + offsetI, j = posJ + offsetJ, comparisonColor = 0;
  if (playerColor == whiteSpace) {
    comparisonColor = blackSpace;
  } else {
    comparisonColor = whiteSpace;
  }

  while ((i < size && i >= 0) && (j < size && j >= 0)) {
    if ((*board).pieces[i][j].currentColor == emptySpace) {
      return 0;
    }
    if ((*board).pieces[i][j].currentColor == playerColor) {
      return 1;
    }
    i += offsetI;
    j += offsetJ;
  }

  return 0;
}

int validMovesRemaining(reversi_board *board, int playerColor) {
  printf("looking for valid moves...\n");
  int size = (*board).size, enemyColor = 0, offsetI = 0, offsetJ = 0, i = 0, j = 0, k = 0, s = 0;

  if (playerColor == whiteSpace) {
    enemyColor = blackSpace;
  } else {
    enemyColor = whiteSpace;
  }
  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      // printf("i = %d; j = %d; k = %d; s = %d\n", i, j, k, s);

      for (k = i - 1; k <= i + 1; k++) {
        // printf("i = %d; j = %d; k = %d; s = %d\n", i, j, k, s);

        if (k < size && k >= 0) {
          for (s = j - 1; s <= j + 1; s++) {

            if (s < size && s >= 0) {
              if ((*board).pieces[i][j].currentColor == enemyColor) {
                if (i != k && j != s) {
                  offsetI = k - i;
                  offsetJ = s - j;
                  if (checkPathValidity(board, playerColor, i, offsetI, j, offsetJ) == 1) {
                    return 1;
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  return 0;
}

void freeReversiBoard(reversi_board *board) {
  int size = (*board).size;

  for (int i = 0; i < size; i++) {
    free((*board).pieces[i]);
  }
  free((*board).pieces);
}
