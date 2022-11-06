#include <stdbool.h>
#include <stdio.h>

#include "Utils.h"

#define MAX_INPUT_SIZE 15

/**
  @requires:
    input between 0 and 2,147,483,647 inclusive
    if input is 0, -1 is returned
  @tested:
    1 and 2,147,483,647
    odd, even, big numbers, small numbers
    powers of 2, powers of 2 +1 or -1
  @returns
    the position of the most significant bit that is set to 1
*/
int msb(unsigned int n) {
  bool binary[bit_per_byte * sizeof(int)];
  decimal_to_binary(n, binary);
  for (int i = bit_per_byte * sizeof(int) - 1; i >= 0; i--) {
    if (binary[i] == true) {
      return i;
    }
  }
  return -1;
}

/**
  @requires:
    input between 0 and 2,147,483,647 inclusive
    if input is 0, -1 is returned
  @tested:
    1 and 2,147,483,647
    odd, even, big numbers, small numbers
    powers of 2, powers of 2 +1 or -1
  @returns
    the position of the least significant bit that is set to 1
*/
int lsb(unsigned int n) {
  bool binary[sizeof(int) * bit_per_byte];
  decimal_to_binary(n, binary);
  for (int i = 0; i < bit_per_byte * sizeof(int); i++) {
    if (binary[i] == true) {
      return i;
    }
  }
  return -1;
}

/**
  Asks the user to enter a positive non-zero integer and then outputs the
  distance between the first and last bits set to 1.
  @expects:
    input between 1 and 2,147,483,647 inclusive
*/
int main(void) {
  printf("-------------------- Arrays --------------------\n");
  char input[MAX_INPUT_SIZE];
  unsigned int n;

  printf("Enter a positive non-zero integer: ");
  fgets(input, sizeof(input), stdin);
  while (sscanf(input, "%u", &n) != 1 || n <= 0) {
    printf("INVALID INPUT! Try again: ");
    fgets(input, sizeof(input), stdin);
  }
  printf("msb(%u)-lsb(%u) = %d\n", n, n, msb(n) - lsb(n));
  return 0;
}