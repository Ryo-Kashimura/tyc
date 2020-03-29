#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 4

int main(int argc, char *argv[]) {
    char buff[MAX_STR_LEN + 1];
    for (int i = 0; i < argc; i++) {
        strncpy(buff, argv[i], MAX_STR_LEN);
        if (MAX_STR_LEN < strlen(argv[i])) {
            buff[MAX_STR_LEN] = '\0';
        } else {
            buff[strlen(argv[i])] = '\0';
        }
        puts(buff);
    }
    return 0;
}
