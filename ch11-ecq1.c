#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "ch11-ecq1.h"

int main(int argc, char** argv) {
    FILE* outputFile;
    if (argc > 1) {
        outputFile = fopen(argv[1], "a");
    } else {
        outputFile = fopen("./ch11-ecq1_output.txt", "r");
        if (!outputFile) {
            outputFile = fopen("./ch11-ecq1_output.txt", "w");
        }
    }
    Text text = readTextFrom(outputFile);
    if (fclose(outputFile)) {
        fputs(strerror(errno), stderr);
        exit(1);
    }
    char command[64];
    for (;;) {
        if (!fgets(command, 63, stdin)) {
            break;
        }
        if (!strcmp(command, "l\n")) {
            show(text);
        } else if (!strcmp(command, "a\n")) {
            appendTo(&text);
        } else if (!strcmp(command, "r\n")) {
            replace(&text);
        } else if (!strcmp(command, "d\n")) {
            deleteCurrentLineOf(&text);
        } else if (command[0] == 'w') {
            outputFile = fopen("./ch11-ecq1_output.txt", "r+");
            char filepath[64];
            if (sscanf(command, "w %s", filepath) == 1) {
                outputFile = fopen(filepath, "w");
            }
            if (!outputFile) {
                outputFile = fopen("./ch11-ecq1_output.txt", "w");
            }
            write(text, outputFile);
            if (fclose(outputFile)) {
                fputs(strerror(errno), stderr);
                exit(1);
            }
        } else if (!strcmp(command, "q\n")) {
            break;
        } else if (atoi(command) != 0) {
            int destLineNumber = atoi(command);
            if (0 < destLineNumber && destLineNumber <= text.lineCount) {
                text.currentLineNumber = atoi(command);
            } else {
                fprintf(stderr, "cannot move to line %i.\n", destLineNumber);
            }
        } else {
            fputs("invalid command.\n", stderr);
        }
    }
    return 0;
}
