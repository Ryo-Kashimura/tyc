#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        puts("usage: ./ch07-ecq4.exe ONE_LETTER");
        return 1;
    }
    if (strlen(argv[1]) != 1) {
        puts("usage: ./ch07-ecq4.exe ONE_LETTER");
        return 1;
    }
    int ch = (int)argv[1][0];
    if (('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z')) {
        puts("A");
    } else if ('0' <= ch && ch <= '9') {
        puts("B");
    } else {
        puts("C");
    }
    return 0;
}
