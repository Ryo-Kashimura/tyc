#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stddef.h>
#include <locale.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "usage: ./ch10-ecq3.exe CSV_FILEPATH\n");
        return 1;
    }
    FILE* src = fopen(argv[1], "r");
    FILE* dest = stdout;
    if (argc > 2) {
        dest = fopen(argv[2], "w");
    }
    // 読込 / 出力処理
    //setlocale(LC_CTYPE, "ja_JP.utf-8");
    int number;
    //wchar_t prefecture[3];
    char prefecture[32];
    int population;
    //wchar_t line[32];
    char line[32];
    fprintf(dest, "項番\t都道府県\t人口\n");
    while (fgets(line, sizeof line, src)) {
        int ret = sscanf(line, "%i, %12[^,], %*12[^,], %i", &number, prefecture, &population);
        if (ret == 3) {
            fprintf(dest, "%4i\t%.16s\t%8i\n", number, prefecture, population);
        }
    }
    if (fclose(src)) {
        fprintf(stderr, "%s\n", strerror(errno));
        return 1;
    }
    if (argc > 2) {
        if (fclose(dest)) {
            fprintf(stderr, "%s\n", strerror(errno));
            return 1;
        }
    }
    return 0;
}
