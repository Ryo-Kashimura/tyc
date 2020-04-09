#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#define MAX_XS 9

typedef struct {
    int x;
    int y;
} X;

// (2)
/*
X* createX(int x, int y) {
    X* p = malloc(sizeof(X));
    if (!p) {
        fprintf(stderr, "%s\n", strerror(errno));
        exit(2);
    }
    p->x = x;
    p->y = y;
    return p;
}
 
int main() {
    X* xs[MAX_XS];
    for (int i = 0; i < MAX_XS; i++) {
        xs[i] = createX(i, i);
    }
    for (int i = 0; i < MAX_XS; i++) {
        printf("x[%i] = (%i, %i)\n", i, xs[i]->x, xs[i]->y);
    }
    return 0;
}
 */

// (3)
X createX(int x, int y) {
    X _x = {x, y};
    return _x;
}

int main() {
    X xs[MAX_XS];
    for (int i = 0; i < MAX_XS; i++) {
        xs[i] = createX(i, i);
    }
    for (int i = 0; i < MAX_XS; i++) {
        printf("x[%i] = (%i, %i)\n", i, xs[i].x, xs[i].y);
    }
    return 0;
}
