#include <stdio.h>

int main(void) {
    char a[] = "This is a string.";
    for (int i = 0; ; i++) {
        if (a[i] == '\0') {
            printf("%s: %i letters\n", a, i);
            break;
        }
    }
    return 0;
}
