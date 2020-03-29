#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        puts("usage: ./ch07-ecq5.exe FIRST_STRING SECOND_STRING");
        return 1;
    }
    for (int i = 1; i < argc; i++) {
        for (int j = 0; j < strlen(argv[i]); j++) {
            int ch = (int)argv[i][j];
            if ('A' <= ch && ch <= 'Z') {
                ch += 'a' - 'A';
            }
            argv[i][j] = (char)ch;
        }
    }
    if (strcmp(argv[1], argv[2]) > 0) {
        puts("1");
    } else if (strcmp(argv[1], argv[2]) == 0) {
        puts("0");
    } else {
        puts("-1");
    }
    return 0;
}
