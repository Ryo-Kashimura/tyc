#include "ch11-ecq1.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define BUFFER_LENGTH 64
#define INITIAL_LINE_COUNT 4
#define INCREMENT_LINE_COUNT 4
#define INITIAL_LINE_LENGTH 32

void append(TextLine* linePointer, Text* textPointer) {
    if (textPointer->lineCount > textPointer->maxLineCount) {
        int requiredLineCount = textPointer->maxLineCount + INCREMENT_LINE_COUNT;
        TextLine** newTextLinePointers = realloc(textPointer->textLinePointers, sizeof(TextLine*) * requiredLineCount);
        if (!newTextLinePointers) {
            fputs(strerror(errno), stderr);
            exit(1);
        }
        textPointer->textLinePointers = newTextLinePointers;
        textPointer->maxLineCount = requiredLineCount;
    }
    textPointer->textLinePointers[textPointer->lineCount++] = linePointer;
    textPointer->currentLineNumber++;
    printf("lineCount        : %i\n", textPointer->lineCount);
    printf("currentLineNumber: %i\n", textPointer->currentLineNumber);
}

void replaceAs(TextLine* linePointer, Text* textPointer) {
    textPointer->textLinePointers[textPointer->currentLineNumber] = linePointer;
    if (textPointer->currentLineNumber < textPointer->maxLineCount) {
        textPointer->currentLineNumber++;
    }
}

TextLine readTextLineFrom(FILE* f) {
    if (!f) {
        fputs(strerror(errno), stderr);
        exit(1);
    }
    TextLine* linePointer = malloc(sizeof(TextLine) + sizeof(char) * INITIAL_LINE_LENGTH);
    if (!linePointer) {
        fputs(strerror(errno), stderr);
        exit(1);
    }
    printf("%p\n", &(linePointer->contentStringLength));
    printf("%p\n", &(linePointer->maxContentStringLength));
    printf("%p\n", &(linePointer->contentString));
    //linePointer->contentString = "";
    linePointer->contentStringLength = 0;
    linePointer->maxContentStringLength = INITIAL_LINE_LENGTH;
    char buffer[BUFFER_LENGTH];
    buffer[0] = '\0';
    for(;;) {
        if (!fgets(buffer, BUFFER_LENGTH, f)) {
            printf("no character found.\n");
            break;
        }
        int requiredLineLength = (linePointer->contentString)? strlen(linePointer->contentString) + strlen(buffer) + 1 : strlen(buffer) + 1;
        printf("requiredLineLength: %i\n", requiredLineLength);
        if (linePointer->maxContentStringLength < requiredLineLength) {
            printf("start reallocation.\n");
            TextLine* newLinePointer = realloc(linePointer, sizeof(TextLine) + sizeof(char) * requiredLineLength);
            //char* newContentString = realloc(linePointer->contentString, sizeof(char) * requiredLineLength);
            printf("finished reallocation.\n");
            if (!newLinePointer) {
                fputs(strerror(errno), stderr);
                exit(1);
            }
            printf("reallocated contentString memory.\n");
            linePointer = newLinePointer;
            //linePointer->contentString = newContentString;
            linePointer->maxContentStringLength = requiredLineLength;
        }
        printf("reallocation skipped.\n");
        printf("buffer: %s\n", buffer);
        if (!linePointer->contentString) {
            printf("contentString is NULL.\n");
            strcpy(linePointer->contentString, buffer);
        } else {
            strcat(linePointer->contentString, buffer);
            printf("contentString: %s\n", linePointer->contentString);
        }
        linePointer->contentStringLength = strlen(linePointer->contentString);
        if (buffer[strlen(buffer) - 1] == '\n') {
            break;
        }
    }
    return *linePointer;
}

Text readTextFrom(FILE* f) {
    if (!f) {
        fputs(strerror(errno), stderr);
        exit(1);
    }
    Text text = {.currentLineNumber = 1, .lineCount = 1, .maxLineCount = INITIAL_LINE_COUNT};
    text.textLinePointers = malloc(sizeof(TextLine*) * text.maxLineCount);
    if (!text.textLinePointers) {
        fputs(strerror(errno), stderr);
        exit(1);
    }
    for (;;) {
        TextLine _line = readTextLineFrom(f);
        if (!_line.contentStringLength) {
            break;
        }
        TextLine* linePointer = malloc(sizeof _line);
        if (!linePointer) {
            fputs(strerror(errno), stderr);
            exit(1);
        }
        *linePointer = _line;
        append(linePointer, &text);
    }
    return text;
}

void show(Text text) {
    for (int i = -2; i < 3; i++) {
        if ((text.currentLineNumber + i < 1) || (text.maxLineCount < text.currentLineNumber + i)) {
            continue;
        }
        printf("%i %s\n", text.currentLineNumber + i, text.textLinePointers[text.currentLineNumber + i]->contentString);
    }
}

void appendTo(Text* textPointer) {
    char command[32];
    for (;;) {
        if (!fgets(command, 31, stdin)) {
            break;
        }
        if (command[0] == '.') {
            break;
        }
        TextLine _line = readTextLineFrom(stdin);
        TextLine* linePointer = malloc(sizeof _line);
        *linePointer = _line;
        append(linePointer, textPointer);
    }
}

void replace(Text* textPointer) {
    char command[32];
    for (;;) {
        if (!fgets(command, 31, stdin)) {
            break;
        }
        if (!strcmp(command, ".")) {
            break;
        }
        TextLine _line = readTextLineFrom(stdin);
        TextLine* linePointer = malloc(sizeof _line);
        *linePointer = _line;
        replaceAs(linePointer, textPointer);
    }
}

void write(Text text, FILE* f) {
    if (!f) {
        fputs(strerror(errno), stderr);
        exit(1);
    }
    for (int i = 0; i < text.lineCount; i++) {
        fputs(text.textLinePointers[i]->contentString, f);
    }
}
