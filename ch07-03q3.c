#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        puts("usage: ./ch07-03q3.exe MORE_THAN_ONE_STRING");
        return 1;
    }
    size_t total_len = 0;
    for (int i = 1; i < argc; i++) {
        total_len += strlen(argv[i]);
    }
    char cat[total_len + 1];
    strcpy(cat, "");
    for (int i = 1; i < argc; i++) {
        strcat(cat, argv[i]);
    }
    for (int i = 0; i < total_len; i++) {
        if ('A' <= (int)cat[i] && (int)cat[i] <= 'Z') {
            cat[i] = (char)((int)cat[i] - 'A' + 'a');
        }
    }
    puts(cat);
    return 0;
}
