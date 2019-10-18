#include <stdio.h>
#include <stdlib.h>

int sum(int x, int y) {
    return x + y;
}

int main(int argc, char *argv[]) {
    int _sum = 0;
    for (int i = 0; i < argc; i++) {
        _sum = sum(_sum, atoi(argv[i]));
    }
    return _sum;
}
