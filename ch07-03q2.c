#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        puts("usage ./ch07-03q2.exe FIRST_STRING SECOND_STRING");
        return 1;
    }
    if (strcmp(argv[1], argv[2]) > 0) {
        puts(argv[1]);
    } else if (strcmp(argv[1], argv[2]) == 0) {
        puts("same!");
    } else {
        puts(argv[2]);
    }
    return 0;
}
