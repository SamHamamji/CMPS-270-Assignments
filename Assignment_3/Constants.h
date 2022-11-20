#define cache_size 64 * 1024
struct cache_count {
  int count;
  char dummy[cache_size - sizeof(int)];
};

extern int *array;
extern const int length;
extern const int value;

extern int count;
extern int private_count[];
extern struct cache_count private_cache_count[64];