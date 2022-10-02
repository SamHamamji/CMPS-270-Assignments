#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

extern const int bit_per_byte;

/**
  Stores the binary representation of the unsigned int `n` in the `binary`
  array, using the little endian order
*/
void decimal_to_binary(int n, bool binary[]);

/**
  Prints the binary representation of the unsigned int `a` in the big endian
  order
*/
void print_binary(unsigned int a);

#endif