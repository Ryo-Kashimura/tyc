#include <stdio.h>

int main() {
    int a, b, c;
    a = b = c = 0;
    int n = scanf("%i %i %i", &a, &b, &c);
    if (!n) {
        fprintf(stderr, "input format: NUMBER NUMBER NUMBER\n");
        return 1;
    } else if (n < 3) {
        fprintf(stderr, "sum of %i number(s): %i\n", n, a + b + c);
        return 1;
    } else {
        fprintf(stdout, "sum of %i number(s): %i\n", n, a + b + c);
    }
    return 0;
}
