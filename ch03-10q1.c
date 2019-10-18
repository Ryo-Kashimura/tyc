#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc == 3) {
        double x = atof(argv[1]);
        double y = atof(argv[2]);
        printf("%f + %f = %f\n", x, y, x + y);
        printf("%f - %f = %f\n", x, y, x - y);
        printf("%f * %f = %f\n", x, y, x * y);
        printf("%f / %f = %f\n", x, y, x / y);
    }
    return 0;
}
