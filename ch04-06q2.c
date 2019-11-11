#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        return 1;
    }
    int x = 0;
    switch (atoi(argv[1])) {
    case 0:
        x = atoi(argv[2]) + atoi(argv[3]);
        break;
    case 1:
        x = atoi(argv[2]) - atoi(argv[3]);
        break;
    case 2:
        x = atoi(argv[2]) * atoi(argv[3]);
        break;
    case 3:
        x = atoi(argv[2]) / atoi(argv[3]);
        break;
    default:
        puts("1st argument should be 0 to 3.");
        return 2;
    }
    printf("%i\n", x);
    return 0;
}
