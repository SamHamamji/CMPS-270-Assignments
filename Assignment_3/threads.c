#include <pthread.h>

#include "Constants.h"
#include "threads.h"

void threads_init(CountingThreads *threads, char *name,
                  void *(*thread_type)(void *), int thread_num) {
  threads->name = name;
  threads->thread_type = thread_type;
  threads->thread_num = thread_num;
}

int threads_run(CountingThreads counting_threads) {
  count = 0;
  pthread_t thread_array[counting_threads.thread_num];
  const int sub_array_length =
      1 + (int)((-1.0 + length) / (counting_threads.thread_num));

  int args[counting_threads.thread_num][3];
  for (int id = 0; id < counting_threads.thread_num; id++) {
    args[id][0] = id * (sub_array_length);
    if (id == counting_threads.thread_num - 1)
      args[id][1] = length;
    else
      args[id][1] = (id + 1) * (sub_array_length);
    args[id][2] = id;
  }
  for (int id = 0; id < counting_threads.thread_num; id++) {
    pthread_create(&thread_array[id], NULL, counting_threads.thread_type,
                   (void *)args[id]);
  }
  for (int id = 0; id < counting_threads.thread_num; id++) {
    pthread_join(thread_array[id], NULL);
  }
  if (counting_threads.thread_type == private_thread) {
    for (int id = 0; id < counting_threads.thread_num; id++) {
      count += private_count[id];
    }
  }
  if (counting_threads.thread_type == cache_thread) {
    for (int id = 0; id < counting_threads.thread_num; id++) {
      count += private_cache_count[id].count;
    }
  }
  return count;
}