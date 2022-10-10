#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 256

/**
  @returns
    a list of the strings contained in `array1` and `array2`, sorted in
    alpha-numerical order.
  @requires:
    `array1` and `array2` are sorted in alpha-numerical order
    The arrays are non-empty
    The length of the strings in the arrays doesn't exceed 256
  @tested:
    Arrays of same / different length
    Identical strings contained in both arrays / the same array
    The empty string
*/
char **merge(char *array1[], int size1, char *array2[], int size2) {
  char **merged = (char **)calloc(sizeof(char *) + 1, size1 + size2);
  int choice1 = 0;
  int choice2 = 0;
  while ((choice1 != size1) && (choice2 != size2)) {
    if (strcmp(array1[choice1], array2[choice2]) < 0) {
      merged[choice1 + choice2] = array1[choice1];
      choice1++;
    } else {
      merged[choice1 + choice2] = array2[choice2];
      choice2++;
    }
  }
  while (choice1 != size1) {
    merged[choice1 + choice2] = array1[choice1];
    choice1++;
  }
  while (choice2 != size2) {
    merged[choice1 + choice2] = array2[choice2];
    choice2++;
  }
  return merged;
}

/**
  Merges `array1` and `array2`, and prints the elements of the new array are
  printed (one on each line)
 */
int main(void) {
  int size1 = 5;
  char *array1[] = {"ab", "ac", "za", "zb", "zczzz"};
  int size2 = 4;
  char *array2[] = {"ac", "b", "sam", "zzc"};

  printf("Array 1: [\"%s\"", (size1) ? array1[0] : "");
  for (int i = 1; i < size1; i++) {
    printf(", \"%s\"", array1[i]);
  }
  printf("]\nArray 2: [\"%s\"", (size2) ? array2[0] : "");
  for (int i = 1; i < size2; i++) {
    printf(", \"%s\"", array2[i]);
  }
  printf("]\n");
  char **merged = merge(array1, size1, array2, size2);

  for (int i = 0; i < size1 + size2; i++) {
    printf("%s\n", merged[i]);
  }
  free(merged);
  return 0;
}