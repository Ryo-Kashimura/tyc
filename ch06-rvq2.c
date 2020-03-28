#include <stdio.h>

int main(void) {
    int array[10];
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            array[i] = i * 2;
        } else {
            array[i] = i * 10;
        }
    }
    for (int i = 0; i < 10; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }
    return 0;
}
