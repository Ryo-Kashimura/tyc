#include <stdio.h>
#include <stdint.h>

int32_t changeEndian(const int32_t x) {
    uint32_t y = 0;
    for (int i = 0; i < 4; i++) {
        uint32_t z = x & (0xff << (3 - i) * 8);
        int leftShiftBitCount = (2 * i - 3) * 8;
        y += (leftShiftBitCount > 0)? z << leftShiftBitCount : z >> (-leftShiftBitCount);
    }
    return (int32_t)y;
}

int main() {
    int32_t a[5] = {0x00bc614e, 0x00000020, 0x00300000, 0x00010000, 0x01000000};
    for (int i = 0; i < 5; i++) {
        fprintf(stdout, "%#010x -> %#010x\n", a[i], changeEndian(a[i]));
    }
    return 0;
}
