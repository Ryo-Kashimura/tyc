#include <stdio.h>

int main(void) {
    int x = 10;
    int y = -x--;
    printf("-x--; => %d\n", x);
    return 0;
}
