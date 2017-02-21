#ifndef CHECKERS_H
#define CHECKERS_H

#include <vector>
#include "checkerspiece.hpp"

class Checkers {
private:
  int size;
  char activeColor;
  char opponentColor;
  std::vector < std::vector < CheckersPiece > > board;
  void printBoard();

public:
  Checkers(int s);
  bool isValidLocation(int i, int j);
  bool isValidMovement(int iOne, int jOne, int iTwo, int jTwo);
  void nextPlayer();
  bool gameOver();
  void play();
};

#endif
