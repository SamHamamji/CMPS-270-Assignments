#include "threads/count_cache.h"
#include "threads/count_mutex.h"
#include "threads/count_private.h"
#include "threads/count_race.h"

typedef struct results {
  double avg_time;
  double success_frequency;
} Results;

int threads_run(void *(*thread_type)(void *), int thread_num);

Results simulate(void *(*thread_type)(void *), int thread_num,
                 int expected_count, int sample_size);