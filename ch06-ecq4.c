#include <stdio.h>

int main(void) {
    int m[2][3] = {{1, 2, 3}, {4, 5, 6}};
    // output m
    printf("m = [");
    for (int k = 0; k < 2; k++) {
        printf("%s[ ", (k < 1)? "" : "     ");
        for (int l = 0; l < 3; l++) {
            printf("%i%s ", m[k][l], (l < 2)? "," : "");
        }
        printf("]%s", (k < 1)? ",\n" : "");
    }
    printf("]\n");
    return 0;
}
