#include <stdio.h>
#include <limits.h>

int main(void) {
    int i = INT_MAX;
    printf("%i\n", i);
    unsigned int u = UINT_MAX;
    printf("%u\n", u);
    long l = LONG_MAX;
    printf("%li\n", l);
    unsigned long ul = ULONG_MAX;
    printf("%lu\n", ul);
    long long ll = LLONG_MAX;
    printf("%lli\n", ll);
    unsigned long long ull = ULLONG_MAX;
    printf("%llu\n", ull);
    return 0;
}
