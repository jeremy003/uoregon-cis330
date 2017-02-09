#include <stdio.h>
#include <stdlib.h>
#include "reversi.h"




int main() {
  reversi_board gameBoard;
  int boardSize = -1, posI = -1, posJ = -1;
  while (boardSize % 2 != 0) {
    printf("Please enter size of board: ");
    scanf("%d", &boardSize);
    getchar();
  }

  gameBoard.size = boardSize;
  allocateReversiBoard(&gameBoard);
  printReversiBoard(&gameBoard);
  printf("Enter two ints: ");
  scanf("%d%d", &posI, &posJ);
  printf("%d\n",isValidMove(&gameBoard, posI, posJ));
  printReversiBoard(&gameBoard);


  freeReversiBoard(&gameBoard);

  return 0;
}
