#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 64
#define SENTENCES_NUMBER 3
#define WORDS_NUMBER 4

void printStringArray(char **array, int size) {
  printf("{");
  for (int i = 0; i < size; i++) {
    if (i == size - 1) {
      printf("\"%s\"", array[i]);
    } else {
      printf("\"%s\", ", array[i]);
    }
  }
  printf("}\n");
}

char **concat(char *array[SENTENCES_NUMBER][MAX_WORD_LENGTH], unsigned int size,
              unsigned int size2) {
  char **concatenation = (char **)calloc(size, size2);
  char sentences[size][MAX_WORD_LENGTH * MAX_WORD_LENGTH / 2];

  for (int sentence_index = 0; sentence_index < size; sentence_index++) {
    strcpy(sentences[sentence_index], "");
    for (int word_index = 0; word_index < size2; word_index++) {
      strcat(sentences[sentence_index], array[sentence_index][word_index]);
      if (word_index != size2 - 1) {
        strcat(sentences[sentence_index], " ");
      }
    }
    concatenation[sentence_index] = sentences[sentence_index];
  }
  return concatenation;
}

int main(void) {
  char *array[WORDS_NUMBER][MAX_WORD_LENGTH] = {{"I", "LOVE", "CODING", ":)"},
                                                {"I", "am", "DONE", ":0"},
                                                {"THIS", "IS", "SPARTA", "!"}};
  char **concatenation = concat(array, SENTENCES_NUMBER, WORDS_NUMBER);
  printStringArray(concatenation, SENTENCES_NUMBER);
  free(concatenation);
  return 0;
}