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
        outputFile = fopen("./ch11-ecq1_output.txt", "w");
    }
    if (!outputFile) {
        fputs(strerror(errno), stderr);
        exit(1);
    }
    Text text = readTextFrom(outputFile);
    char command[64];
    for (;;) {
        if (!fgets(command, 63, stdin)) {
            break;
        }
        if (command[0] == 'a') {
            appendTo(&text);
        } else if (command[0] == 'r') {
            replace(&text);
        } else if (command[0] == 'l') {
            show(text);
        } else if (command[0] == 'q') {
            break;
        } else if (command[0] == 'w') {
            char filepath[64];
            int ret = sscanf(command, "w %s", filepath);
            FILE* _outputFile = outputFile;
            if (ret == 1) {
                _outputFile = fopen(filepath, "w");
            }
            write(text, _outputFile);
        } else if (atoi(command) != 0) {
            text.currentLineNumber = atoi(command);
        } else {
            fputs("invalid command.\n", stdout);
        }
    }
    if (fclose(outputFile)) {
        fputs(strerror(errno), stderr);
        exit(1);
    }
    return 0;
}
