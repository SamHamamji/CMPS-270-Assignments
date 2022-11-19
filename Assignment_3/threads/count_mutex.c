#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#include "../Constants.h"

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