#include <stdio.h>
#include <stdlib.h>

int *compare(const void *x, const void *y) {
    return *(int*)y - *(int*)x;
}

int main(int argc, char *argv[]) {
    int array[argc - 1];
    for (int i = 1; i < argc; i++) {
        array[i - 1] = atoi(argv[i]);
    }
    qsort(array, argc - 1, sizeof(int), compare);
    for (int i = 0; i < argc - 1; i++) {
        printf("%i\n", array[i]);
    }
    return 0;
}
