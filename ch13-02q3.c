#include <stdio.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        fputs("usage: ./ch13-02q3.exe CAPITAL_LETTER\n", stderr);
        return 1;
    }
    char capital = argv[1][0];
    if (capital < 0x41 || 0x5A < capital) {
        fputs("usage: ./ch13-02q3.exe CAPITAL_LETTER\n", stderr);
        return 1;
    }
    fprintf(stdout, "%c\n", capital | 0x20);
    return 0;
}
