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

  int ranges[counting_threads.thread_num][2];
  for (int index = 0; index < counting_threads.thread_num; index++) {
    ranges[index][0] = index * (sub_array_length);
    if (index == counting_threads.thread_num - 1)
      ranges[index][1] = length;
    else
      ranges[index][1] = (index + 1) * (sub_array_length);
    pthread_create(&thread_array[index], NULL, counting_threads.thread_type,
                   (void *)ranges[index]);
  }
  for (int index = 0; index < counting_threads.thread_num; index++) {
    pthread_join(thread_array[index], NULL);
  }
  return count;
}