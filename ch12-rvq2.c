#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int argc;
    char* argv[];
} Arg;

void printArg(Arg* arg) {
    for (int i = 0; i < arg->argc; i++) {
        printf("%s\n", arg->argv[i]);
    }
}

int main(int argc, char** argv) {
    Arg* pa;
    pa = malloc(sizeof(Arg) + sizeof(char*) * argc);
    pa->argc = argc;
    for (int i = 0; i < argc; i++) {
        pa->argv[i] = malloc(sizeof(char) * (strlen(argv[i]) + 1));
        strcpy(pa->argv[i], argv[i]);
    }
    printArg(pa);
    for (int i = 0; i < argc; i++) {
        free(pa->argv[i]);
    }
    free(pa);
}
