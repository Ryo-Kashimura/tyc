#include <stdio.h>
#include <stdint.h>

int main(void) {
    uint32_t x = -10;
    int16_t y = x;
    uint16_t z = x;
    x = z;
    printf("x = %d, y = %d\n", x, y);
    return 0;
}

