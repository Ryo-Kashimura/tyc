#include <stdio.h>
#include <stdbool.h>

int main(void) {
    bool shouldBreakLoop = false;
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            for (int z = 0; z < 5; z++) {
                printf("x: %i, y: %i, z: %i\n", x, y, z);
                shouldBreakLoop = x == 1 && y == 2 && z == 3;
                if (shouldBreakLoop) {
                    break;
                }
            }
            if (shouldBreakLoop) {
                break;
            }
        }
        if (shouldBreakLoop) {
            break;
        }
    }
    puts("end");
    return 0;
}
