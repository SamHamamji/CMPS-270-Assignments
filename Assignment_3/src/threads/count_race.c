#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../include/Constants.h"
#include "../../include/threads/count_race.h"

void *race_condition_thread(void *args) {
  int *range = (int *)args;
  for (int index = range[0]; index < range[1]; index++)
    if (array[index] == value)
      count++;
  return NULL;
}
