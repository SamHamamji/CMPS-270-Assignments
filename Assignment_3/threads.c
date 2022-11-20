#include <pthread.h>
#include <sys/time.h>

#include "Constants.h"
#include "threads.h"

int threads_run(void *(*thread_type)(void *), int thread_num) {
  count = 0;
  pthread_t thread_array[thread_num];
  const int sub_array_length = 1 + (int)((-1.0 + length) / (thread_num));

  int args[thread_num][3];
  for (int id = 0; id < thread_num; id++) {
    args[id][0] = id * (sub_array_length);
    if (id == thread_num - 1)
      args[id][1] = length;
    else
      args[id][1] = (id + 1) * (sub_array_length);
    args[id][2] = id;
    pthread_create(&thread_array[id], NULL, thread_type, (void *)args[id]);
  }
  for (int id = 0; id < thread_num; id++) {
    pthread_join(thread_array[id], NULL);
  }

  if (thread_type == private_thread) {
    for (int id = 0; id < thread_num; id++) {
      count += private_count[id];
    }
  } else if (thread_type == cache_thread) {
    for (int id = 0; id < thread_num; id++) {
      count += private_cache_count[id].count;
    }
  }
  return count;
}

Results simulate(void *(*thread_type)(void *), int thread_num,
                 int expected_count, int sample_size) {
  int n;
  struct timeval start;
  struct timeval end;
  double total_time = 0;
  int total_success = 0;

  for (int i = 0; i < sample_size; i++) {
    gettimeofday(&start, NULL);
    n = threads_run(thread_type, thread_num);
    gettimeofday(&end, NULL);

    if (n == expected_count)
      total_success++;
    total_time +=
        end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec) / 1000000.0;
  }

  return (struct results){total_time / sample_size,
                          (double)total_success / sample_size};
}
