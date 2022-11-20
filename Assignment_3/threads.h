#include "threads/count_cache.h"
#include "threads/count_mutex.h"
#include "threads/count_private.h"
#include "threads/count_race.h"

typedef struct countingThreads {
  char *name;
  void *(*thread_type)(void *);
  int thread_num;
} CountingThreads;

int threads_run(CountingThreads threads);

void threads_init(CountingThreads *threads, char *name,
                  void *(*thread_type)(void *), int thread_num);