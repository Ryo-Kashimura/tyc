#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    FILE* f = fopen("./ch10-02q3_test.txt", "r");
    if (!f) {
        fprintf(stderr, "%s\n", strerror(errno));
        return 1;
    }
    int birth, death;
    char name[12];
    char line[27];
    while (fgets(line, sizeof line, f)) {
        int ret = sscanf(line, "%*i, %11[^,], %i, %i", name, &birth, &death);
        if (ret == 3) {
            printf("%-11s %4i - %4i\n", name, birth, death);
        }
    }
    return 0;
}
