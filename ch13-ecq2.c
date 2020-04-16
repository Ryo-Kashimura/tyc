#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    if (argc < 3) {
        fputs("usage: ./ch13-ecq2.exe NUMBER NUMBER\n", stderr);
        return 1;
    }
    int a, _a, b, q, r;
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    if (b == 0) {
        fputs("second NUMBER must not be 0.\n", stderr);
        return 1;
    }
    _a = a;
    q = 0;
    while (_a >= b) {
        int i;
        for (i = 1; _a > b << i; i++);
        _a -= b << (i - 1);
        q += 1 << (i - 1);
    }
    r = _a;
    fprintf(stdout, "%i / %i = %i ... %i\n", a, b, q, r);
    return 0;
}
