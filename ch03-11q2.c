#include <stdio.h>
#include <stdlib.h>

#define PRINT(op) printf("%i\n", x op y);

int main(int argc, char *argv[]) {
    if (argc == 3) {
        int x = atoi(argv[1]);
        int y = atoi(argv[2]);
        PRINT(+);
        PRINT(-);
        PRINT(*);
        PRINT(/);
    }
    return 0;
}
