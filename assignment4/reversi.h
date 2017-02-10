#ifndef REVERSI_H
#define REVERSI_H

#include "chip.h"

class Reversi {
private:
  Chip** board;
  int size;
  char activePlayer;
  bool checkPath(int i, int j, int offsetI, int offsetJ);
  ~Reversi();

public:
  Reversi(int s);
  void print();
  void nextPlayer();
  bool isValidMove(int i, int j);
  bool validMovesRemaining();
};

#endif
