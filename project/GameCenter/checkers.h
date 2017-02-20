#ifndef CHECKERS_H
#define CHECKERS_H

#include <vector>
#include "checkerspiece.h"

class Checkers {
private:
  int size;
  char activeColor;
  char opponentColor;
  std::vector < std::vector < CheckersPiece > > board;
  void printBoard();

public:
  Checkers(int s);
  void play();

};

#endif
