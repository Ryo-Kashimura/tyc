#include <stdio.h>

int main(void) {
    for (int i = 1; i <= 50; i++) {
        if (i % 3 == 0) {
            printf("Fizz");
        }
        if (i % 5 == 0) {
            printf("Buzz");
        }
        if (i % 3 == 0 || i % 5 == 0) {
            printf("\n");
            continue;
        }
        printf("%i\n", i);
    }
    return 0;
}
