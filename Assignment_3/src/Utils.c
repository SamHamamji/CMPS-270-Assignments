#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/Utils.h"

void print_array(const int *array, const int len) {
  printf("{");
  if (len < 0) {
    printf("ERROR: array length is negative in print_array()\n");
    exit(1);
  }

  if (len != 0)
    printf(" %d", array[0]);
  for (int index = 1; index < len; index++)
    printf(", %d", array[index]);

  printf(" }\n");
}

void generate_array(int *array, const int len, const int min, const int max) {
  if (min > max) {
    printf("ERROR: min is greater than max in generate_array()\n");
    exit(1);
  }
  if (len < 0) {
    printf("ERROR: array length is negative in generate_array()\n");
    exit(1);
  }
  if (array == NULL) {
    printf("ERROR: array is null in generate_array()\n");
    exit(1);
  }

  srand((unsigned int)time(NULL));
  for (int index = 0; index < len; index++) {
    array[index] = min + rand() % (max - min + 1);
  }
};

int sequential_count(const int *array, const int len, const int value) {
  if (len < 0) {
    printf("ERROR: array length is negative in sequential_count()\n");
    exit(1);
  }
  int count = 0;
  for (int i = 0; i < len; i++) {
    if (array[i] == value) {
      count++;
    }
  }
  return count;
}