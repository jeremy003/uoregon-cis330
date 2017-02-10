#include "reversi.h"

Reversi::Reversi(int s) {
  size = s;
  activePlayer = 'b';

  board = new Chip*[size];
  for (int i = 0; i < size; i++) {
    board[i] = new Chip[size];
  }
}

bool Reversi::checkPath(int i, int j, int offsetI, int offsetJ) {

  return false;
}

void Reversi::print() {

}

void Reversi::nextPlayer() {
  if (activePlayer == 'b') {
    activePlayer = 'w';
  } else {
    activePlayer = 'b';
  }
}

bool Reversi::isValidMove(int i, int j) {
  return false;
}

bool Reversi::validMovesRemaining() {
  return false;
}

Reversi::~Reversi() {
  for (int i = 0; i < size; i++) {
    delete [] board[i];
  }
  delete [] board;
}
