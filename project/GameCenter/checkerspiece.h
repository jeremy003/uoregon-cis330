#ifndef CHECKERSPIECE_H
#define CHECKERSPIECE_H

class CheckersPiece {
private:
  // Private variables. reverse is true if the piece has reached the other side of the board, so it can go backwards.
  char space;
  bool reverse;
public:
  CheckersPiece();
  char getSpace();
  void setSpace(char c);
  bool canReverse();
  void setReverse(bool b);
};

#endif
