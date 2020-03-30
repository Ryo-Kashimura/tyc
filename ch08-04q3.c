#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *compare(const void *x, const void *y) {
    return strcmp(*(char**)x, *(char**)y);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        puts("usage: ./ch08-04q3.exe MORE_THAN_ONE_STRING");
        return 1;
    }
    char *array[argc - 1];
    for (int i = 0; i < argc - 1; i++) {
        array[i] = argv[i + 1];
    }
    qsort(array, argc - 1, sizeof(char*), compare);
    for (int i = 0; i < argc - 1; i++) {
        puts(array[i]);
    }
    return 0;
}
