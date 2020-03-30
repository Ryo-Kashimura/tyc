#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        puts("usage: ./ch08-rvq4.exe STRING");
        return 1;
    }
    printf("%s => ", argv[1]);
    for (int i = strlen(argv[1]); i >= 0; i--) {
        printf("%c", argv[1][i]);
    }
    printf("\n");
    return 0;
}
