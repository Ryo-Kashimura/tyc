#include <stdio.h>

int main() {
    int n;
    double d;
    int h;
    char s[32];
    int ret = scanf("%i %lf %x %s", &n, &d, &h, s);
    if (ret == 4) {
        printf("%06i, %.2f, %#010x, %s!\n", n, d, h, s);
    }
    return 0;
}
