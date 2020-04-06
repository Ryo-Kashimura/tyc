#include <stdio.h>
#include <string.h>
#define HELLO "hello "

char* create_hello(char* dest, const char* name) {
    strcpy(dest, HELLO);
    strcat(dest, name);
    return dest;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        puts("usage: ./ch09-04q2.exe YOUR_NAME");
        return 1;
    }
    char hello[strlen(HELLO) + strlen(argv[1]) + 1];
    puts(create_hello(hello, argv[1]));
    return 0;
}
