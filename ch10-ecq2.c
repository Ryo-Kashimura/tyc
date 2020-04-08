#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE* f;
    if (argc > 1) {
        if (!(f = fopen(argv[1], "r"))) {
            fprintf(stderr, "%s\n", strerror(errno));
            return 1;
        }
    } else {
        f = stdin;
    }
    char ch;
    while ((ch = fgetc(f)) != EOF) {
        if (fputc(ch, stdout) == EOF) {
            fprintf(stderr, "%s\n", strerror(errno));
            return 1;
        }
    }
    if (argc > 1) {
        if (fclose(f)) {
            fprintf(stderr, "%s\n", strerror(errno));
            return 1;
        }
    }
    return 0;
}
