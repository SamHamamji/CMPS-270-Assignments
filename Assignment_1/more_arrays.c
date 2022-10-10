#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Utils.h"

#define MAX_WORD_LENGTH 64
#define SENTENCES_NUMBER 3
#define WORDS_NUMBER 4

/**
  @returns a 1D array containing the concatenation of elements in each element
    of `array` with a space separation between each two elements
  @expects:
    The number of words in each row of `array` is the same
    `size1` and `size2` are non-zero
  @tested:
    Empty arrays (`array1`, `array2`, both)
*/
char **concat(char *array[SENTENCES_NUMBER][MAX_WORD_LENGTH], unsigned int size,
              unsigned int size2) {
  char **concatenated = (char **)calloc(size, size2);
  char sentences[size][MAX_WORD_LENGTH * MAX_WORD_LENGTH / 2];

  for (int sentence_index = 0; sentence_index < size; sentence_index++) {
    strcpy(sentences[sentence_index], "");
    for (int word_index = 0; word_index < size2; word_index++) {
      strcat(sentences[sentence_index], array[sentence_index][word_index]);
      if (word_index != size2 - 1) {
        strcat(sentences[sentence_index], " ");
      }
    }
    concatenated[sentence_index] = sentences[sentence_index];
  }
  return concatenated;
}

int main(void) {
  char *array[WORDS_NUMBER][MAX_WORD_LENGTH] = {{"I", "LOVE", "CODING", ":)"},
                                                {"I", "am", "DONE", ":0"},
                                                {"THIS", "IS", "SPARTA", "!"}};
  char **concatenated = concat(array, SENTENCES_NUMBER, WORDS_NUMBER);
  printStringArray(concatenated, SENTENCES_NUMBER);
  free(concatenated);
  return 0;
}