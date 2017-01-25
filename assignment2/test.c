#include <stdio.h>
#include "triangle.h"

int main() {
  print5Triangle();

  int **triangle;

  int user_choice = 0;

  while (user_choice < 1 || user_choice > 5) {
    printf("Please enter the height of the triangle [1-5]: ");
    scanf("%d", &user_choice);

    getchar();
  }

  printf("%d\n", user_choice);

  return 0;
}
