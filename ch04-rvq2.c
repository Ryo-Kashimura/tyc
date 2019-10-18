#include <stdio.h>
#include <limits.h>
#include <float.h>

#define PRINT(x, f) printf(f"\n", x)

int main(void) {
    PRINT(INT_MAX, "%i");
    PRINT(INT_MIN, "%i");
    PRINT(DBL_MAX, "%f");
    PRINT(-DBL_MAX, "%f");
    return 0;
}
