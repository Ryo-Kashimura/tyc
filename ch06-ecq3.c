#include <stdio.h>

int main(void) {
    // initialize m
    int m[2][3];
    int i = 0;
    do {
        int j = 0;
        while (j < 3) {
            m[i][j] = i * 3 + j + 1;
            j++;
        }
    } while (++i < 2);
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
