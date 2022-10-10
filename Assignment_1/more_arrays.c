#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Utils.h"

#define MAX_WORD_LENGTH 64
#define SENTENCES_NUMBER 3
#define WORDS_NUMBER 4

/**
  @param
    `array` 2d matrix of strings
    `rows` number of arrays in `array`
    `columns` number of strings in each array of `array`
  @returns a 1D array containing the concatenation of elements in each element
    of `array` with a space separation between each two elements
  @expects:
    The number of words in each row of `array` is the same
    `rows` and `columns` are non-zero
    Empty arrays (`array1`, `array2`, both)
  @tested:
    rows > columns
    columns > rows
    rows = columns
    rows = columns = 1
*/
char **concat(char *array[SENTENCES_NUMBER][MAX_WORD_LENGTH], unsigned int rows,
              unsigned int columns) {
  char **concatenated = (char **)calloc(rows, columns);
  char sentences[rows][MAX_WORD_LENGTH * MAX_WORD_LENGTH / 2];

  for (int sentence_index = 0; sentence_index < rows; sentence_index++) {
    strcpy(sentences[sentence_index], "");
    for (int word_index = 0; word_index < columns; word_index++) {
      strcat(sentences[sentence_index], array[sentence_index][word_index]);
      if (word_index != columns - 1) {
        strcat(sentences[sentence_index], " ");
      }
    }
    concatenated[sentence_index] = sentences[sentence_index];
  }
  return concatenated;
}

/**
  Function testing the `char **concat(char *array[][], int, int)` function
  To change the value of `array`, one has to adjust the macros
  `SENTENCES_NUMBER` and `WORDS_NUMBER`
*/
int main(void) {
  char *array[WORDS_NUMBER][MAX_WORD_LENGTH] = {{"I", "LOVE", "CODING", ":)"},
                                                {"I", "am", "DONE", ":0"},
                                                {"THIS", "IS", "SPARTA", "!"}};
  char **concatenated = concat(array, SENTENCES_NUMBER, WORDS_NUMBER);
  printStringArray(concatenated, SENTENCES_NUMBER);

  free(concatenated);
  return 0;
}