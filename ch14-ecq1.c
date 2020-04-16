#include <stdio.h>
#define PRINT_ARGV(valName, val, idx, format) fprintf(stdout, #valName "[%i] = " #format "\n", idx, val)
#define PRINT_VAL(valName, format) fprintf(stdout, #valName " = " #format "\n", valName)

int main(int argc, char** argv) {
    PRINT_VAL(argc, %i);
    for (int i = 0; i < argc; i++) {
        PRINT_ARGV(argv, argv[i], i, %s);
    }
    return 0;
}
