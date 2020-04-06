#include <stdio.h>

int main() {
    char name[32];
    int birthYear, deathYear;
    for (;;) {
        int ret = scanf("%*i, %31[^,], %i, %i", name, &birthYear, &deathYear);
        if (ret == EOF) {
            break;
        }
        printf("%-11s %4d-%4d\n", name, birthYear, deathYear);
    }
    return 0;
}
