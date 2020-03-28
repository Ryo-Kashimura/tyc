#include <stdio.h>

int main(void) {
    /* (1)
    for (int n = 9; 0 <= n; n--) {
        printf("%i\n", n);
    }
     */
    /* (2)
    int n = 10;
    while (n-- > 0) {
        printf("%i\n", n);
    }
     */
    /* (3)
    int n = 9;
    do {
        printf("%i\n", n);
    } while (n-- > 0);
     */
    return 0;
}
