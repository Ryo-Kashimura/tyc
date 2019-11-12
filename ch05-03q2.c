#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    int x = INT_MAX;
    for (int i = 1; i < argc; i++) {
        int divisor = atoi(argv[i]);
        if (divisor == 0) {
            puts("divisor is 0.");
            return 1;
        }
        x /= divisor;
    }
    printf("x = %i\n", x);
    return 0;
}
