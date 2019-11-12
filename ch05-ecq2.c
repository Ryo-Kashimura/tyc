#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int main(void) {
    // (1) two for loops
    /*
    int16_t i16 = 1;
    int16_t i = 1;
    for (; 0 < i16 * i && i16 * i <= INT16_MAX; i++) {
        i16 *= i;
    }
    printf("16bit = %i, last_multiplier = %i\n", i16, i - 1);
    int32_t i32 = 1;
    int32_t j = 1;
    for (; 0 < i32 * j && i32 * j <= INT32_MAX; j++) {
        i32 *= j;
    }
    printf("32bit = %i, last_multiplier = %i\n", i32, j - 1);
     */
    // (2) one for loop
    int i = 1;
    int j = 1;
    int16_t i16Max = 0;
    int32_t i32Max = 0;
    bool int16Convertible = true;
    bool int32convertible = true;
    for (int x = 1; int32convertible; i++) {
        int16Convertible = int16Convertible && 0 < (int16_t)(x * i) && (int16_t)(x * i) <= INT16_MAX;
        int32convertible = int32convertible && 0 < x * i && x * i <= INT32_MAX;
        if (int16Convertible) {
            i16Max = x * i;
            j = i;
        }
        if (int32convertible) {
            printf("x = %i\n", (int16_t)x);
            i32Max = x * i;
            x *= i;
        }
    }
    printf("16bit = %i, last_multiplier = %i\n", i16Max, j - 1);
    printf("32bit = %i, last_multiplier = %i\n", i32Max, i - 1);
    return 0;
}
