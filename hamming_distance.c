#include "Utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 30

typedef enum { PAIR_OF_POSITIVE_INTS, NEGATIVE_INT } InputState;

/**
  @returns the hamming distance between the binary representations of int `a`
  and int `b`
*/
int hamming_distance(int a, int b) {
  int counter = 0;
  bool binary_a[bit_per_byte * sizeof(int)];
  bool binary_b[bit_per_byte * sizeof(int)];
  decimal_to_binary(a, binary_a);
  decimal_to_binary(b, binary_b);

  for (int i = 0; i < bit_per_byte * sizeof(int); i++) {
    if (binary_a[i] != binary_b[i]) {
      counter++;
    }
  }
  return counter;
}

/**
  Asks for input and stores the input in `ptr_a` and `ptr_b`
  @returns the state of the input (PAIR_OF_POSITIVE_INTS or NEGATIVE_INT)
*/
InputState take_input(int *ptr_a, int *ptr_b) {
  char input[MAX_INPUT_SIZE];
  fgets(input, sizeof(input), stdin);
  if (sscanf(input, "%d %d", ptr_a, ptr_b) == 2) {
    if (*ptr_a < 0 || *ptr_b < 0) {
      return NEGATIVE_INT;
    }
    return PAIR_OF_POSITIVE_INTS;
  } else if (sscanf(input, "%d", ptr_a) == 1 && *ptr_a < 0) {
    return NEGATIVE_INT;
  } else {
    printf("INVALID INPUT! Try again: ");
    return take_input(ptr_a, ptr_b);
  }
}

/**
  @requires:
    input between 0 and 2,147,483,647 inclusive
  @tested:
    symmetry (a/b and b/a)
    big number / big number
    small number / big number
    small number / small number
  @edgecases: 0 and 2,147,483,647
*/
int main(void) {
  int a;
  int b;

  printf("Enter pairs of positive integers (separated by a space), and a "
         "negative (non-zero) integer to stop.\n\n");

  while (true) {
    printf("Enter a and b: ");
    if (take_input(&a, &b) == NEGATIVE_INT) {
      printf("Negative input: process terminated\n");
      break;
    }
    printf("Hdist(%d, %d) = %d\n\n", a, b, hamming_distance(a, b));
  }
  return 0;
}