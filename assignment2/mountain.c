#include <stdlib.h>
#include <stdio.h>
#include "mountain.h"

void printNumberMountain(const int numPeaks, int *heights, int ***triangles) {
  int *widths = (int *) malloc(numPeaks * sizeof(int));
  int totalWidth = 0;
  int maxHeight = heights[0];
  for (int i = 0; i < numPeaks; i++) {
    widths[i] = (heights[i] * 2) - 1;
    totalWidth += widths[i];
    if (heights[i] > maxHeight) {
      maxHeight = heights[i];
    }
  }

  (*triangles) = (int **) malloc(maxHeight * sizeof(int *));
  for (int i = 0; i < maxHeight; i++) {
    (*triangles)[i] = (int *) malloc(totalWidth * sizeof(int));
    for (int j = 0; j < totalWidth; j++) {
      (*triangles)[i][j] = -1;
    }
  }

  int widthOffset = 0;
  for (int k = 0; k < numPeaks; k++) {
    int heightOffset = maxHeight - heights[k];
    int count = 0;
    for (int i = 0; i < heights[k]; i++) {
      for (int j = heights[k] - 1 - i; j < heights[k] + i; j++) {
        (*triangles)[i+heightOffset][j+widthOffset] = count;
        count++;
      }
      count = 0;
    }
    widthOffset += (heights[k] * 2) - 1;
  }

  for (int i = 0; i < maxHeight; i++) {
    for (int j = 0; j < totalWidth; j++) {
      if ((*triangles)[i][j] < 0) {
        printf("  ");
      } else {
        printf("%d ", (*triangles)[i][j]);
      }
    }
    printf("\n");
  }

  for (int i = 0; i < maxHeight; ++i)
    free((*triangles)[i]);
  free((*triangles));
}

int main() {
  int **triangles;

  int peaks = 0;

  while (peaks < 1 || peaks > 5) {
    printf("Please enter the number of peaks in the mountain [1-5]: ");
    scanf("%d", &peaks);

    getchar();
  }

  int *heights = (int *) malloc(peaks * sizeof(int));

  for (int i = 0; i < peaks; i++) {
    while (heights[i] < 1 || heights[i] > 5) {
      printf("Please enter the heights of peak %d [1-5]: ", (i+1));
      scanf("%d", &heights[i]);

      getchar();
    }
  }

  printNumberMountain(peaks, heights, &triangles);

  free(heights);
  
  return 0;
}
