#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
const int POSSIBLE_VALUES[3] = {1, 2, 3};

/**
  Prints the int* `array` to the stdout as a table
*/
void printArray(int *array) {
  printf("Index Value\n");
  for (int i = 0; i < SIZE; i++) {
    printf("%5d %5d\n", i, array[i]);
  }
}

/**
  Prints the int* `array` to the stdout as a histogram
*/
void arrayHistogram(int array[]) {
  printf("Value Frequency Histogram\n");
  char stars[9];
  unsigned int counter;
  for (int i = 0; i < sizeof(POSSIBLE_VALUES) / sizeof(int); i++) {
    counter = 0;
    for (int j = 0; j < SIZE; j++) {
      if (array[j] == POSSIBLE_VALUES[i]) {
        counter++;
      }
    }

    printf("%5d %9d", POSSIBLE_VALUES[i], counter);
    for (int j = 9; j > 0; j--) {
      printf("%c", (j <= counter) ? '*' : ' ');
    }
    printf("\n");
  }
}

/**
  Changes the int[] `array` by swapping the elements at `index1` and `index2`
*/
void swapValues(int array[], int index1, int index2) {
  int temp = array[index1];
  array[index1] = array[index2];
  array[index2] = temp;
}

/**
  Sorts the int[] `array` using bubbleSort
  @tested:
    empty array / singleton
    array with identical elements
*/
void bubbleSort(int array[]) {
  for (int i = 0; i < SIZE; i++)
    for (int j = 0; j < i; j++)
      if (array[j] > array[i])
        swapValues(array, i, j);
}

/**
  @returns a double representing the median of the int[] `array`
  @tested:
    odd/even array length
    median is an integer: {1, 1, 1, 1, 2, 2, 2, 2, 3, 3}
    median is a decimal: {1, 1, 1, 1, 1, 2, 2, 2, 3, 3}
*/
double median(int array[]) {
  int copy[SIZE];
  for (int i = 0; i < SIZE; i++) {
    copy[i] = array[i];
  }
  bubbleSort(copy);
  int middle = (SIZE - 1) / 2;
  return (SIZE % 2 == 1) ? copy[middle]
                         : (copy[middle] + copy[middle + 1]) / 2.;
}

/**
  @returns an int representing the first occuring mode of the int[] `array`
  @tested:
    completely separate
*/
int mode(int array[]) {
  struct counter {
    int value;
    int occurences;
  };
  struct counter mode;
  mode.occurences = 0;
  struct counter current;
  for (int value_index = 0; value_index < sizeof(POSSIBLE_VALUES) / sizeof(int);
       value_index++) {
    current.value = POSSIBLE_VALUES[value_index];
    current.occurences = 0;
    for (int i = 0; i < SIZE; i++) {
      if (array[i] == current.value) {
        current.occurences++;
      }
    }
    if (current.occurences > mode.occurences) {
      mode.value = current.value;
      mode.occurences = current.occurences;
    }
  }
  return mode.value;
}

/**
  @returns whether the array is sorted
*/
int isSorted(int array[]) {
  for (int i = 0; i < SIZE - 1; i++)
    if (array[i] > array[i + 1])
      return 0;
  return 1;
}

/**
  Function that tests all the previous functions
*/
int main(void) {
  printf("---------- MSB and LSB ----------\n");
  int array[SIZE] = {1, 2, 1, 3, 1, 1, 1, 3, 2, 2};
  arrayHistogram(array);

  printf("\n");
  printf("The array is%s sorted\n", (isSorted(array)) ? "" : " not");
  printArray(array);

  printf("\n");
  printf("Sorting...\n");
  bubbleSort(array);
  printf("The array is%s sorted\n", (isSorted(array)) ? "" : " not");
  printArray(array);

  printf("\n");
  printf("Median: %f\n", median(array));
  printf("Mode: %d\n", mode(array));
}