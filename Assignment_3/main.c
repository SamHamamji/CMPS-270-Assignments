#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Constants.h"
#include "Utils.h"
#include "threads.h"

int main() {
  const int min = 0;
  const int max = 5;
  array = (int *)calloc(length, sizeof(int));
  generate_array(array, length, min, max);

  const int simulation_num = 7;
  const int thread_num[] = {1, 2, 4, 8, 16, 32, 64};
  CountingThreads threads[simulation_num];

  printf("sequential: %d\n", sequential_count(array, length, value));

  int n;
  for (int i = 0; i < simulation_num; i++) {
    threads_init(&threads[i], "race condition", race_condition_thread,
                 thread_num[i]);
    n = threads_run(threads[i]);
    printf("%s: %d\n", threads[i].name, n);
  }

  free(array);
}
