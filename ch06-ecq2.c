#include <stdio.h>

int main(void) {
    int lineCount = 1;
    char ch;
    while (lineCount < 4) {
        ch = getchar();
        if (ch != '\n') {
            printf("%c", ch);
        } else {
            lineCount++;
        }
    }
    printf("\n");
    return 0;
}
