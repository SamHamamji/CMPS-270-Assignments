#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

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

  int n;
  struct timeval start;
  struct timeval end;
  double diff;

  gettimeofday(&start, NULL);
  n = sequential_count(array, length, value);
  gettimeofday(&end, NULL);
  diff = end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec) / 1000000.0;
  printf("sequential: %f sec\n%d\n", diff, n);

  for (int i = 0; i < simulation_num; i++) {
    threads_init(&threads[i], "cache", cache_thread, thread_num[i]);
    gettimeofday(&start, NULL);
    n = threads_run(threads[i]);
    gettimeofday(&end, NULL);
    diff =
        end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec) / 1000000.0;
    printf("%s %dth: %f sec\n%d\n", threads[i].name, thread_num[i], diff, n);
  }

  free(array);
}
