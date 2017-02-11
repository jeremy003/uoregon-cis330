
#include "reversi.h"

using namespace std;

Reversi::Reversi(int s) {
  activePlayer = 'b';
  opponentPlayer = 'w';
  size = s;
  int mid = s / 2;

  board.assign(s, std::vector<char>(s, 'o'));
  board[mid][mid] = 'w';
  board[mid-1][mid] = 'b';
  board[mid-1][mid-1] = 'w';
  board[mid][mid-1] = 'b';
}

bool Reversi::checkPath(int posI, int posJ, int offsetI, int offsetJ) {
  int i = posI + offsetI, j = posJ + offsetJ;

  while ((i < size && i >= 0) && (j < size && j >= 0)) {
    if (board[i][j] == 'o') {
      return 0;
    }
    if (board[i][j] == activePlayer) {
      // Flip pieces back to original point
      posI = posI - offsetI;
      posJ = posJ - offsetJ;
      while (i != posI || j != posJ) {
        board[i][j] = activePlayer;
        i -= offsetI;
        j -= offsetJ;
      }
      board[i][j] = activePlayer;
      return 1;
    }
    i += offsetI;
    j += offsetJ;
  }

  return 0;

  return false;
}

void Reversi::run() {
  int i = -1, j = -1, passCounter = 0;

  while (passCounter < 2) {
    print();
    while (!isValidMove(i, j)) {
      cout << "Enter coordinates for (" << activePlayer << ") player in format i, j. Or enter -1 -1 to pass. To end the game, both players must pass consecutively: ";
      cin >> i >> j;
      if (i == -1 && j == -1) {
        passCounter += 1;
        cout << "pass counter: " << passCounter << endl;
        break;
      } else {
        passCounter = 0;
      }
      cout << "pass counter: " << passCounter << endl;
    }
    nextPlayer();
  }
  printScore();
}

void Reversi::print() {
  cout << "  ";
  for (int i = 0; i < size; i++) {
    cout << i << " ";
  }
  cout << endl;

  for (int i = 0; i < size; i++) {
    cout << i << " ";
    for (int j = 0; j < size; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}

void Reversi::printScore() {
  int countW = 0, countB = 0;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (board[i][j] == 'w') {
        countW++;
      } else if (board[i][j] == 'b') {
        countB++;
      }
    }
  }

  cout << "Score:" << endl << "Black: " << countB << endl << "White: " << countW << endl;
}

void Reversi::nextPlayer() {
  char temp = activePlayer;
  activePlayer = opponentPlayer;
  opponentPlayer = temp;
}

bool Reversi::isValidMove(int posI, int posJ) {
  int offsetI = 0, offsetJ = 0;
  bool valid = false;
  if (posI < 0 || posI >= size || posJ < 0 || posJ >= size) {
    return false;
  }
  if (board[posI][posJ] != 'o') {
    return false;
  }

  for (int i = posI - 1; i <= posI + 1; i++) {
    if (i < size && i >= 0) {
      for (int j = posJ - 1; j <= posJ + 1; j++) {
        if (j < size && j >= 0) {
          if (board[i][j] == opponentPlayer) {
            offsetI = i - posI;
            offsetJ = j - posJ;

            if (checkPath(i, j, offsetI, offsetJ))
              valid = 1;
          }
        }
      }
    }
  }

  return valid;
}
