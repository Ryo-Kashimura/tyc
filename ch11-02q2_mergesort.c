#include "ch11-02q2_mergesort.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void merge(void** left, void** right, int leftLength, int rightLength, bool (*areIncreasingOrder)(const void*, const void*)) {
    void** merged = malloc(sizeof(void*) * (leftLength + rightLength));
    if (!merged) {
        fprintf(stderr, "%s\n", strerror(errno));
        exit(1);
    }
    int leftIdx, rightIdx;
    leftIdx = rightIdx = 0;
    while ((leftIdx < leftLength) || (rightIdx < rightLength)) {
        if ((leftIdx < leftLength) && (rightIdx < rightLength)) {
            if (areIncreasingOrder(left[leftIdx], right[rightIdx])) {
                merged[leftIdx + rightIdx] = left[leftIdx];
                leftIdx++;
            } else {
                merged[leftIdx + rightIdx] = right[rightIdx];
                rightIdx++;
            }
        } else if ((leftIdx >= leftLength) && (rightIdx < rightLength)) {
            merged[leftIdx + rightIdx] = right[rightIdx];
            rightIdx++;
        } else if ((leftIdx < leftLength) && (rightIdx >= rightLength)) {
            merged[leftIdx + rightIdx] = left[leftIdx];
            leftIdx++;
        }
    }
    for (size_t i = 0; i < (size_t)leftLength; i++) {
        left[i] = merged[i];
    }
    for (size_t i = 0; i < (size_t)rightLength; i++) {
        right[i] = merged[leftLength + i];
    }
    free(merged);
}

void myMergeSort(void** array, int length, bool (*areIncreasingOrder)(const void*, const void*)) {
    if (length < 2) {
        return;
    }
    int leftLength = length / 2;
    int rightLength = length - length / 2;
    void** left = array;
    void** right = array + leftLength;
    myMergeSort(left, leftLength, areIncreasingOrder);
    myMergeSort(right, rightLength, areIncreasingOrder);
    merge(left, right, leftLength, rightLength, areIncreasingOrder);
}

