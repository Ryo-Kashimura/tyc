#include <stdio.h>

int main(void) {
    /* (1)
    for (n = 1; n <= 10; n++) {
        printf("%i\n", n);
    }
     */
    /* (2)
    int n = 0;
    while (n++ < 10) {
        printf("%i\n", n);
    }
     */
    /* (3)
    int n = 1;
    do {
        printf("%i\n", n);
    } while (n++ < 10);
     */
    return 0;
}
