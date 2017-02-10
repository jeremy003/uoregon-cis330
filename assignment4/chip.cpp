#include "chip.h"

Chip::Chip() {
  color = 'o';
}

void Chip::setColor(char c) {
  color = c;
}

char Chip::getColor() {
  return color;
}
