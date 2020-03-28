#include <stdio.h>

int main(void) {
    int array[10] = {};
    for (int i = 0, j = 9; i < 10 && 0 <= j; i++, j--) {
        array[i] = j;
        printf("array[%d] = %d\n", i, array[i]);
    }
    return 0;
}
