#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        puts("usage: ./ch06-01q2.c SOURCE_FILEPATH DESTINATION_FILEPATH");
        return 1;
    }
    FILE *src = fopen(argv[1], "r");
    FILE *dest = fopen(argv[2], "w");
    char ch;
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }
    fclose(src);
    fclose(dest);
    return 0;
}
