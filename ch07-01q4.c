#include <stdio.h>
#include <stdint.h>
#include <locale.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        puts("usage: ./ch07-01q4.exe ONE_CAPITAL_LETTER_OR_ONE_DIGIT");
        return 1;
    }
    setlocale(LC_CTYPE, "ja_JP.utf-8");
    if (u'A' <= argv[1][0] && argv[1][0] <= u'Z') {
        printf("%lc\n", argv[1][0] - u'A' + u'a');
    } else if (u'0' <= argv[1][0] && argv[1][0] <= u'9') {
        printf("%i\n", argv[1][0] - u'0' + 3);
    } else {
        puts("英大文字または数字を入力してください");
        return 1;
    }
    return 0;
}
