#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

int main() {
    // (1)
    FILE* oneK = fopen("./ch11-rvq3_1K.data", "w");
    if (!oneK) {
        fprintf(stderr, "%s\n", strerror(errno));
        return 1;
    }
    for (int i = 0; i < 1000; i++) {
        if (fputc('\0', oneK) == EOF) {
            fprintf(stderr, "%s\n", strerror(errno));
            if (fclose(oneK)) {
                fprintf(stderr, "%s\n", strerror(errno));
                return 1;
            }
            return 1;
        }
    }
    if (fclose(oneK)) {
        fprintf(stderr, "%s\n", strerror(errno));
        return 1;
    }
    // (2)
    FILE* _oneK = fopen("./ch11-rvq3_1K.data", "r+");
    if (!_oneK) {
        fprintf(stderr, "%s\n", strerror(errno));
        return 1;
    }
    while (true) {
        if (fseek(_oneK, 31, SEEK_CUR)) {
            fprintf(stderr, "%s\n", strerror(errno));
            if (fclose(_oneK)) {
                fprintf(stderr, "%s\n", strerror(errno));
                return 1;
            }
        }
        if (ftell(_oneK) > 1000) {
            break;
        }
        if (fputc('A', _oneK) == EOF) {
            break;
        }
    }
    if (fclose(_oneK)) {
        fprintf(stderr, "%s\n", strerror(errno));
        return 1;
    }
    // (3)
    FILE* __oneK = fopen("./ch11-rvq3_1K.data", "r");
    if (!__oneK) {
        fprintf(stderr, "%s\n", strerror(errno));
        return 1;
    }
    char ch;
    fprintf(stdout, "0--1--2--3--4--5--6--7--8--9--A--B--C--D--E--F-\n");
    for (int i = 0; i < 1000; i++) {
        if ((ch = fgetc(__oneK)) == EOF) {
            break;
        }
        fprintf(stdout, "%02x", ch);
        if ((i + 1) % 16 == 0) {
            fprintf(stdout, "\n");
        } else {
            fprintf(stdout, " ");
        }
    }
    fprintf(stdout, "\n");
    if (fclose(__oneK)) {
        fprintf(stderr, "%s\n", strerror(errno));
        return 1;
    }
    return 0;
}
