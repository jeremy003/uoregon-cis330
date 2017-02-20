#include "checkerspiece.h"

CheckersPiece::CheckersPiece() {
  space = ' ';
  reverse = false;
}

char CheckersPiece::getSpace() {
  return space;
}

void CheckersPiece::setSpace(char c) {
  space = c;
}

bool CheckersPiece::canReverse() {
  return reverse;
}

void CheckersPiece::setReverse(bool b) {
  reverse = b;
}
