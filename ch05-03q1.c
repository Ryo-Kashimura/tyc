#include <stdio.h>

int main(void) {
    int x = 1;
    for (; x > 0;) {
        x += x * 2;
    }
    printf("x = %i\n", x);
    return 0;
}
