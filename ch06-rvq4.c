#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int a = 1;
    for (int i = 1; i < argc; i++) {
        a *= atoi(argv[i]);
        printf("%d ", atoi(argv[i]));
        if (i < argc - 1) {
            printf("* ");
        }
    }
    printf("= %d\n", a);
    return 0;
}
