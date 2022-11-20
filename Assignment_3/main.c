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

  int n;
  struct timeval start;
  struct timeval end;
  gettimeofday(&start, NULL);
  n = sequential_count(array, length, value);
  gettimeofday(&end, NULL);
  double diff =
      end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec) / 1000000.0;
  printf("sequential: %f sec\n%d\n\n", diff, n);

  const int thread_types_len = 4;
  void *(*thread_types[4])(void *args) = {race_condition_thread, mutex_thread,
                                          private_thread, cache_thread};
  const char *thread_names[] = {"race_condition", "mutex", "private", "cache"};

  const int simulation_num = 100;
  const int thread_num[] = {1, 2, 4, 8, 16, 32, 64};

  Results results;

  for (int type_index = 0;
       type_index < (sizeof(thread_types) / sizeof(void *(*)(void *args)));
       type_index++) {
    printf("\n%s thread\n", thread_names[type_index]);
    for (int thread_num_index = 0;
         thread_num_index < sizeof(thread_num) / sizeof(int);
         thread_num_index++) {
      results = simulate(thread_types[type_index], thread_num[thread_num_index],
                         n, simulation_num);
      printf("%d thread(s):\n", thread_num[thread_num_index]);
      printf("Avg time: %f sec\n", results.avg_time);
      printf("Sucess frequency: %f\n", results.success_frequency);
    }
  }
  free(array);
}
