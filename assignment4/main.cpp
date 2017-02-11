#include <iostream>
#include "reversi.h"

int main() {
  int size = 0;
  std::cout << "Enter board size: ";
  std::cin >> size;
  Reversi *game = new Reversi(size);
  game->run();
  delete game;
}
