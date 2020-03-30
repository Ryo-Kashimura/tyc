#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(void) {
    int32_t a[] = {0, 1, 2, 3, 4, 5};
    for (size_t i = 0; i < (sizeof a) / (sizeof a[0]); i++) {
        printf("%i\n", a[i]);
    }
    return 0;
}
