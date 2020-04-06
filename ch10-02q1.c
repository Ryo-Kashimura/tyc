#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>

int main() {
    // (1)
    FILE* alla = fopen("./ch10-02q1-all_a.txt", "w");
    for (int i = 0; i < 128; i++) {
        if (fputc('a', alla) == EOF) {
            fclose(alla);
            puts(strerror(errno));
            return 1;
        }
    }
    fclose(alla);
    // (2)
    FILE* allAa = fopen("./ch10-02q1-all_a.txt", "r+");
    if (!allAa) {
        puts(strerror(errno));
        fclose(allAa);
        return 1;
    }
    for (int i = 0; i < 4; i++) {
        if (fseek(allAa, (long)(4 * (2 << i)), SEEK_SET)) {
            puts(strerror(errno));
            fclose(allAa);
            return 1;
        }
        char ch;
        if ((ch = fgetc(allAa)) == EOF) {
            puts(strerror(errno));
            fclose(allAa);
            return 1;
        }
        if (fseek(allAa, -1L, SEEK_CUR)) {
            puts(strerror(errno));
            fclose(allAa);
            return 1;
        }
        if (fputc(toupper(ch), allAa) == EOF) {
            puts(strerror(errno));
            fclose(allAa);
            return 1;
        }
    }
    fclose(allAa);
    return 0;
}
