#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#include "Utils.h"

int *array;
const int length = 10000;
const int value = 1;
int count = 0;
pthread_mutex_t lock;

void *mutex_thread(void *args) {
  int *range = (int *)args;
  for (int index = range[0]; index < range[1]; index++)
    if (array[index] == value) {
      pthread_mutex_lock(&lock);
      count++;
      pthread_mutex_unlock(&lock);
    }
  return NULL;
};

int main() {
  const int min = 0;
  const int max = 5;
  const int thread_num = 4;
  array = (int *)calloc(length, sizeof(int));
  const int sub_array_length = 1 + (int)((-1.0 + length) / (thread_num));

  generate_array(array, length, min, max);
  // print_array(array, length);

  printf("sequential: %d\n", sequential_count(array, length, value));

  pthread_t threads[thread_num];
  int ranges[thread_num][2];
  for (int index = 0; index < thread_num; index++) {
    ranges[index][0] = index * (sub_array_length);
    if (index == thread_num - 1)
      ranges[index][1] = length;
    else
      ranges[index][1] = (index + 1) * (sub_array_length);
    pthread_create(&threads[index], NULL, mutex_thread, (void *)ranges[index]);
  }

  for (int index = 0; index < thread_num; index++) {
    pthread_join(threads[index], NULL);
  }
  printf("race_condition: %d\n", count);
  free(array);
}
