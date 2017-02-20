#include <iostream>
#include "checkers.h"
#include "checkerspiece.h"

Checkers::Checkers(int s) {
  size = s;
  activeColor = 'W';
  opponentColor = 'B';

  board.assign(s, std::vector<CheckersPiece>(s, CheckersPiece()));

  int colCount = 0;
  int rowCount = 0;
  for (int i = 0; i < size; i++) {
    if (rowCount % 2 == 0) {
      colCount = 0;
    } else {
      colCount = 1;
    }
    for (int j = 0; j < size; j++) {
      if (colCount % 2 == 0) {
        // board[i][j] = '*';
        board[i][j].setSpace('*');
      }
      colCount++;
    }
    rowCount++;
  }

  colCount = 0;
  rowCount = 0;
  char activePlacement = opponentColor;
  int midRow = (size / 2) - 2;
  for (int i = 0; i < size; i++) {
    if (rowCount % 2 == 0) {
      colCount = 0;
    } else {
      colCount = 1;
    }
    for (int j = 0; j < size; j++) {
      if (colCount % 2 == 1) {
        // board[i][j] = activePlacement;
        board[i][j].setSpace(activePlacement);
      }
      colCount++;
    }
    rowCount++;
    if (i == midRow) {
      i += 2;
      activePlacement = activeColor;
    }
  }

}

void Checkers::printBoard() {
  std::cout << "    ";
  for (int i = 0; i < size; i++) {
    std::cout << i << "   ";
  }
  std::cout << std::endl << "   ";
  for (int i = 0; i < size; i++) {
    std::cout << "--- ";
  }
  std::cout << std::endl;
  for (int i = 0; i < size; i++) {
    std::cout << i << " | ";
    for (int j = 0; j < size; j++) {
      std::cout << board[i][j].getSpace() << " | ";
    }
    std::cout << std::endl << "   ";
    for (int k = 0; k < size; k++) {
      std::cout << "--- ";
    }
    std::cout << std::endl;
  }
}

void Checkers::play() {
  std::cout << "Welcome to Checkers!!!" << std::endl << "This is the Checkers board:" << std::endl;
  printBoard();
  std::cout << "Here's how to look at this:" << std::endl
  << "The numbers represent the coordinates of each cell. For example, the top right cell is '0 9' and the bottom right cell is '9 9'." << std::endl
  << "The '*' character represents a white cell. Like in normal checkers, players can only move on the black cells." << std::endl
  << "The 'B' character represents a black chip, and the 'W' character represents a white chip." << std::endl;
}
