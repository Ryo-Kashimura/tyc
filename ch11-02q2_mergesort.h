#include <stdbool.h>

void merge(void** left, void** right, int leftLength, int rightLength, bool (*areIncreasingOrder)(const void*, const void*));

void myMergeSort(void** array, int length, bool (*areIncreasingOrder)(const void*, const void*));
