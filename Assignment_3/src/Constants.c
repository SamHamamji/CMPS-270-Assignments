#include <stdlib.h>

#include "../include/Constants.h"

int *array;
const int length = 1000000;
const int value = 1;

int count = 0;
int private_count[64];
struct cache_count private_cache_count[64];