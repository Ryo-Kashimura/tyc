#include <stdio.h>
#include <stdlib.h>

// definition for problem (1)
// #define MUL(x, y) atoi(x) * atoi(y)
// definition for problem (2)
#define MUL(x, y) (x) * (y)

int main(int argc, char *argv[]) {
    if (argc > 2) {
        // statements for problem (1)
        /*
        printf("%i\n", MUL(argv[1], argv[2]));
        printf("%i\n", MUL(argv[1], "8"));
         */
        // statements for problem (2)
        printf("%i\n", MUL(atoi(argv[1]), atoi(argv[2])));
        printf("%i\n", MUL(atoi(argv[1]), 8 - 3));
    }
    return 0;
}
