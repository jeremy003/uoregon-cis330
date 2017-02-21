#include <iostream>
#include "checkerspiece.hpp"
#include "checkers.hpp"

using namespace std;

Checkers::Checkers(int s) {
  size = s;
  activeColor = 'W';
  opponentColor = 'B';

  board.assign(s, vector<CheckersPiece>(s, CheckersPiece()));

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
  cout << "    ";
  for (int i = 0; i < size; i++) {
    cout << i << "   ";
  }
  cout << endl << "   ";
  for (int i = 0; i < size; i++) {
    cout << "--- ";
  }
  cout << endl;
  for (int i = 0; i < size; i++) {
    cout << i << " | ";
    for (int j = 0; j < size; j++) {
      cout << board[i][j].getSpace() << " | ";
    }
    cout << endl << "   ";
    for (int k = 0; k < size; k++) {
      cout << "--- ";
    }
    cout << endl;
  }
}

bool Checkers::isValidLocation(int i, int j) {
  // Check if inbounds
  if (i < 0 || i >= size || j < 0 || j >= size)
    return false;

  if (board[i][j].getSpace() == activeColor)
    return true;

  return false;
}

bool Checkers::gameOver() {
  bool hasBlack = false;
  bool hasWhite = false;
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      if (board[i][j].getSpace() == 'B') {
        hasBlack = true;
      } else if (board[i][j].getSpace() == 'W') {
        hasWhite = true;
      }
      if (hasBlack && hasWhite) {
        return false;
      }
    }
  }
  if (hasWhite && !hasBlack) {
    cout << "White wins!" << endl;
  } else if (!hasWhite && hasBlack) {
    cout << "Black wins!" << endl;
  }
  return true;
}

void Checkers::nextPlayer() {
  char c = activeColor;
  activeColor = opponentColor;
  opponentColor = c;
}

void Checkers::play() {
  int iCoord = -1, jCoord = -1;

  cout << "Welcome to Checkers!!!" << endl << "This is the Checkers board:" << endl;
  printBoard();
  cout << "Here's how to look at this:" << endl
  << " - The numbers represent the coordinates of each cell. For example, the top right cell is '0 9' and the bottom right cell is '9 9'." << endl
  << " - The '*' character represents a white cell. Like in normal checkers, players can only move on the black cells." << endl
  << " - The 'B' character represents a black chip, and the 'W' character represents a white chip." << endl;

  while (!gameOver()) {
    cout << activeColor << "'s turn. Select a piece to move by entering i and j value (row, column): ";
    cin >> iCoord >> jCoord;
    if (isValidLocation(iCoord, jCoord)) {
      cout << "Valid location" << endl;
    } else {
      cout << "Invalid location" << endl;
    }
    nextPlayer();
  }
}
