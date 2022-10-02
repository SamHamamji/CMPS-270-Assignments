#include <stdbool.h>
#include <stdio.h>

#define bit_per_byte 8

void decimal_to_binary(int n, bool *binary);
void print_binary(int a);

/**
  Stores the binary representation of `n` in the `binary` array, using the
  little endian order
*/
inline void decimal_to_binary(int n, bool binary[]) {
  for (int i = 0; i < bit_per_byte * sizeof(int); i++) {
    binary[i] = n % 2;
    n /= 2;
  }
}

inline void print_binary(int a) {
  bool binary[bit_per_byte * sizeof(int)];
  decimal_to_binary(a, binary);
  int len = bit_per_byte * sizeof(int);
  for (int j = len - 1; j >= 0; j--) {
    printf("%d", binary[j]);
  }
}