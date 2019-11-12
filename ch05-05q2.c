#include <stdio.h>

int main(void) {
    for (int i = 0; i < 8; i++) {
        switch (i % 3) {
        case 0:
            puts("Fizz");
            break;
        case 1:
            puts("Fizz + 1");
            break;
        case 2:
            puts("end");
            return 0;
        default:
            puts("never come here.");
        }
    }
    return 0;
}
