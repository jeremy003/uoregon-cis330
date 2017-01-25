#include "triangle.h"
#include <stdio.h>

void print5Triangle() {
  int triangle[5][9];

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 9; j++) {
      triangle[i][j] = -1;
    }
  }

  int count = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 4 - i; j < 5 + i; j++) {
      triangle[i][j] = count;
      count++;
    }
    count = 0;
  }

  printf("print 5 triangle:\n");
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 9; j++) {
      if (triangle[i][j] < 0) {
        printf("  ");
      } else {
        printf("%d ", triangle[i][j]);
      }
    }
    printf("\n");
  }
}
