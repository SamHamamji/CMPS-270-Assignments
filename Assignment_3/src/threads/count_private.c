#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../include/Constants.h"
#include "../../include/threads/count_private.h"

void *private_thread(void *args) {
  int *input = (int *)args;
  int id = input[2];
  private_count[id] = 0;
  for (int index = input[0]; index < input[1]; index++)
    if (array[index] == value) {
      private_count[id]++;
    }
  return NULL;
}