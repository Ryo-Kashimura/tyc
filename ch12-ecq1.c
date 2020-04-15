#include <stdio.h>
#include <stdlib.h>
#include "ch12-ecq1_syntaxtree.h"

int main() {
    char ch;
    ch = getchar();
    if (ch != '(') {
        fputs("syntax error.\n", stderr);
        exit(1);
    }
    Cell* root = generateSyntaxTree();
    //showSyntaxTreeOf(root);
    printf("%i\n", computedFrom(root));
    return 0;
}
