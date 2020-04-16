#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        fputs("usage: ./ch13-02q2.exe NUMBER\n", stderr);
        return 1;
    }
    int number = atoi(argv[1]);
    if (number & 0x1) {
        printf("odd number entered.\n");
    } else {
        printf("even number entered.\n");
    }
    return 0;
}
