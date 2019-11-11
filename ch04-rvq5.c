#include <stdio.h>
#include <stdint.h>

int main(void) {
    uint8_t a = -1;
    int16_t b = a;
    int32_t c = b;
    int64_t d = c;
    printf("uint8_t: %u\n", a);
    printf("int16_t: %i\n", b);
    printf("int32_t: %i\n", c);
    printf("int64_t: %lli\n", d);
    return 0;
}
