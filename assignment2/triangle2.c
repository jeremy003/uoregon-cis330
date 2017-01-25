#include "triangle.h"
#include <stdio.h>
#include <stdlib.h>

/* Allocate a triangle of height "height" (a 2-D array of int) */
void allocateNumberTriangle(const int height, int ***triangle) {
  int width = (height * 2) - 1;

  (*triangle) = (int **) malloc ( height * sizeof(int *) );
  for (int i = 0; i < height; i++) {
    (*triangle)[i] = (int *) malloc ( width * sizeof(int) );
    for (int j = 0; j < width; j++) {
      (*triangle)[i][j] = 0;
    }
  }

  printf("triangle memory space allocated\n");


}

/* Initialize the 2-D triangle array */
void initializeNumberTriangle(const int height, int **triangle) {
  int width = (height * 2) - 1;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      triangle[i][j] = -1;
    }
  }

  int count = 0;
  for (int i = 0; i < height; i++) {
    for (int j = height - 1 - i; j < height + i; j++) {
      triangle[i][j] = count;
      count++;
    }
    count = 0;
  }

  printf("initialized number triangle\n");
}

/* Print a formatted triangle */
void printNumberTriangle(const int height, int **triangle) {
  int width = (height * 2) - 1;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (triangle[i][j] < 0) {
        printf("  ");
      } else {
        printf("%d ", triangle[i][j]);
      }
    }
    printf("\n");
  }
}

/* Free the memory for the 2-D triangle array */
void deallocateNumberTriangle(const int height, int ***triangle) {
  for (int i = 0; i < height; ++i)
    free((*triangle)[i]);
  free((*triangle));

  printf("memory freed\n");
}
