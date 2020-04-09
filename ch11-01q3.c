#include <stdio.h>

typedef struct {
    int x;
    int y;
} POINT;

POINT move(POINT p, int x, int y) {
    p.x += x;
    p.y += y;
    printf("p (in move)  = (%3i, %3i), &p = %p\n", p.x, p.y, &p);
    return p;
}

int main() {
    POINT p = {1, 2};
    printf("p (original) = (%3i, %3i), &p = %p\n", p.x, p.y, &p);
    POINT pp = move(p, 10, -10);
    printf("p (returned) = (%3i, %3i), &p = %p\n", pp.x, pp.y, &pp);
    return 0;
}
