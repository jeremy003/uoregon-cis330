#include <stdio.h>
#include <stdlib.h>
#include "reversi.h"




int main() {
  reversi_board gameBoard;
  int boardSize = -1, posI = -1, posJ = -1, done = 0, currentColor = blackSpace;
  while (boardSize % 2 != 0) {
    printf("Please enter size of board: ");
    scanf("%d", &boardSize);
    getchar();
  }

  gameBoard.size = boardSize;
  allocateReversiBoard(&gameBoard);
  printReversiBoard(&gameBoard);

  while (done == 0) {
    while (posI >= boardSize || posI < 0 || posJ >= boardSize || posJ < 0 || isValidMove(&gameBoard, currentColor, posI, posJ) != 1) {
      printf("Current player: %d\nEnter a point (i j): ", currentColor);
      scanf("%d%d", &posI, &posJ);
      getchar();
    }
    printReversiBoard(&gameBoard);
    if (currentColor == blackSpace) {
      currentColor = whiteSpace;
    } else {
      currentColor = blackSpace;
    }
    if (validMovesRemaining(&gameBoard, currentColor) == 0) {
      done = 1;
    }
  }



  freeReversiBoard(&gameBoard);

  return 0;
}
