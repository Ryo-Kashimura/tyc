#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    /* (1)
    int32_t a = 0x01234567;
    uint8_t *b = &a;
    printf("a = %08x, b = %02x\n", a, *b);
    if (*b == 0x01) {
        puts("big endian");
    } else {
        puts("little endian");
    }
     */
    // (2)
    if (argc != 2) {
        puts("usage: ./ch08-03q3.exe 32-BIT-INTEGER");
        return 1;
    }
    int32_t a = atoi(argv[1]);
    int32_t result = 0;
    for (int i = 0; i < 4; i++) {
        uint8_t *p = &a;
        int32_t temp = *(p + (uint8_t)i);
        result += temp << (24 - i * 8);
    }
    printf("%08x\n", result);
    return 0;
}
