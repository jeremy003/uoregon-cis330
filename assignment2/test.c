#include <stdio.h>
#include "triangle.h"

int main() {
  print5Triangle();

  int **triangle;

  int height = 0;

  while (height < 1 || height > 5) {
    printf("Please enter the height of the triangle [1-5]: ");
    scanf("%d", &height);

    getchar();
  }

  printf("%d\n", height);

  allocateNumberTriangle(height, &triangle);
  initializeNumberTriangle(height, triangle);
  printNumberTriangle(height, triangle);
  deallocateNumberTriangle(height, &triangle);

  return 0;
}
