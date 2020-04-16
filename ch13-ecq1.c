#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        fputs("usage: ./ch13-ecq1.exe NUMBER\n", stderr);
        return 1;
    }
    unsigned int number = (unsigned int)atoi(argv[1]);
    int minDigit;
    for (minDigit = 0; minDigit < (int)sizeof(int) * 8; minDigit++) {
        if ((number & 0x1 << minDigit) >> minDigit == 0x1 || minDigit >= (int)sizeof(int) * 8 - 1) {
            break;
        }
    }
    unsigned int mask = 0;
    if (minDigit < 31) {
        for (int digit = 0; digit <= minDigit; digit++) {
            mask |= 0x1 << digit;
        }
        number = (((~number) >> (minDigit + 1)) << (minDigit + 1)) | (number & mask);
    } else {
        mask = 0xffffffff;
    }
    fprintf(stdout, "%i\n", (int)number);
    return 0;
}
