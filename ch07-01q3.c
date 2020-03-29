#include <stdio.h>
#include <stdint.h>
#include <locale.h>

int main(void) {
    setlocale(LC_CTYPE, "ja_JP.utf-8");
    for (int16_t i = u'\x306A'; i <= u'\x306E'; i++) {
        printf("%lc\n", i);
    }
    return 0;
}
