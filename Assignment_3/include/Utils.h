#pragma once

/**
  Prints `array` to standard out
  @input:
    `const int *array` an array of integers
    `const int len` the length of `array`
  @expects:
    `len >= 0`
  @examples:
    { }
    { 1 }
    { 1, -4, 0, 2 }
*/
void print_array(const int *array, const int len);

/**
  Fills `array` with random integers whose values range from min to max
  (inclusive)
  @input:
    `int *array` an array of integers
    `const int len` the length of `array`
    `const int min` the minimum possible value generated
    `const int max` the maximum possible value generated
  @expects:
    `len >= 0`
    `min < max`
*/
void generate_array(int *array, const int len, const int min, const int max);

/**
  Counts the number occurrences of `value` in `array`
  @input:
    `const int *array` an array of integers
    `const int len` the length of `array`
    `const int value` the element to be counted
  @expects:
    `len >= 0`
*/
int sequential_count(const int *array, const int len, const int value);