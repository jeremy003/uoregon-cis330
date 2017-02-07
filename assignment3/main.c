#include <stdio.h>
#include <stdlib.h>
#include "reversi.h"




int main() {
  reversi_board gameBoard;
  int boardSize = 0, posX = -1, posY = -1;
  printf("Please enter size of board: ");
  scanf("%d", &boardSize);

  gameBoard.size = boardSize;
  allocateReversiBoard(&gameBoard);
  printReversiBoard(&gameBoard);

  


  return 0;
}
