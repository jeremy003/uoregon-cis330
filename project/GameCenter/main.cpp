#include <iostream>
#include "checkers.h"

using namespace std;

int main() {
  Checkers* game = new Checkers(10);
  game->play();
  delete game;
}
