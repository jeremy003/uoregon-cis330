#ifndef REVERSI_H
#define REVERSI_H

#include <vector>
#include <iostream>

class Reversi {
private:
  int size;
  char activePlayer;
  char opponentPlayer;
  std::vector < std::vector < char > > board;
  bool checkPath(int i, int j, int offsetI, int offsetJ);

public:
  Reversi(int s);
  void run();
  void print();
  void printScore();
  void nextPlayer();
  bool isValidMove(int i, int j);
  bool validMovesRemaining();
};

#endif
