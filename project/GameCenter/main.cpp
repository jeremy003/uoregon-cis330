#include <iostream>
#include "checkerspiece.hpp"
#include "checkers.hpp"

using namespace std;

int main() {
  Checkers* game = new Checkers(10);
  game->play();
  delete game;
}
