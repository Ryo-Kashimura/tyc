#include <stdio.h>

int main(void) {
    int x = 10;
    int y = x++;
    int z = --x;
    printf("x = %d, y = %d, z = %d\n", x, y, z);
    return 0;
}
