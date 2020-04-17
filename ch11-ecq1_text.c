#include "ch11-ecq1.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define BUFFER_LENGTH 64
#define INITIAL_LINE_COUNT 4
#define INCREMENT_LINE_COUNT 4
#define INITIAL_LINE_LENGTH 32

void insert(TextLine* linePointer, Text* textPointer, int lineNumber) {
    if (textPointer->lineCount >= textPointer->maxLineCount) {
        int requiredLineCount = textPointer->maxLineCount + INCREMENT_LINE_COUNT;
        TextLine** newTextLinePointers = realloc(textPointer->textLinePointers, sizeof(TextLine*) * requiredLineCount);
        if (!newTextLinePointers) {
            fputs(strerror(errno), stderr);
            exit(1);
        }
        textPointer->textLinePointers = newTextLinePointers;
        textPointer->maxLineCount = requiredLineCount;
    }
    for (int i = textPointer->lineCount - 1; i >= lineNumber - 1; i--) {
        textPointer->textLinePointers[i + 1] = textPointer->textLinePointers[i];
    }
    textPointer->textLinePointers[lineNumber - 1] = linePointer;
    textPointer->currentLineNumber = lineNumber;
    textPointer->lineCount++;
}

TextLine* readTextLineFrom(FILE* f) {
    if (!f) {
        fputs(strerror(errno), stderr);
        exit(1);
    }
    TextLine* linePointer = malloc(sizeof(TextLine) + sizeof(char) * INITIAL_LINE_LENGTH);
    if (!linePointer) {
        fputs(strerror(errno), stderr);
        exit(1);
    }
    linePointer->contentString = malloc(sizeof(char) * INITIAL_LINE_LENGTH);
    if (!linePointer->contentString) {
        fputs(strerror(errno), stderr);
        exit(1);
    }
    linePointer->contentString[0] = '\0';
    linePointer->contentStringLength = 0;
    linePointer->maxContentStringLength = INITIAL_LINE_LENGTH;
    char buffer[BUFFER_LENGTH];
    buffer[0] = '\0';
    for(;;) {
        if (!fgets(buffer, BUFFER_LENGTH, f)) {
            break;
        }
        if (!strncmp(buffer, ".\n", 2)) {
            break;
        }
        int requiredLineLength = linePointer->contentStringLength + strlen(buffer);
        if (linePointer->maxContentStringLength < requiredLineLength) {
            TextLine* newLinePointer = realloc(linePointer, sizeof(TextLine) + sizeof(char) * requiredLineLength);
            newLinePointer->contentString = realloc(linePointer->contentString, sizeof(char) * requiredLineLength);
            if (!newLinePointer) {
                fputs(strerror(errno), stderr);
                exit(1);
            }
            if (!newLinePointer->contentString) {
                fputs(strerror(errno), stderr);
                exit(1);
            }
            linePointer = newLinePointer;
            linePointer->maxContentStringLength = requiredLineLength;
        }
        if (linePointer->contentString) {
            if (linePointer->contentStringLength > 1) {
                if (buffer[strlen(buffer) - 1] == '\n') {
                    strncat(linePointer->contentString, buffer, strlen(buffer) - 1);
                } else {
                    strcat(linePointer->contentString, buffer);
                }
            } else {
                if (buffer[strlen(buffer) - 1] == '\n') {
                    strncpy(linePointer->contentString, buffer, strlen(buffer) - 1);
                } else {
                    strcpy(linePointer->contentString, buffer);
                }
            }
            linePointer->contentStringLength = strlen(linePointer->contentString);
        }
        if (buffer[strlen(buffer) - 1] == '\n') {
            break;
        }
    }
    return linePointer;
}

Text readTextFrom(FILE* f) {
    if (!f) {
        fputs(strerror(errno), stderr);
        exit(1);
    }
    Text text = {.currentLineNumber = 0, .lineCount = 0, .maxLineCount = INITIAL_LINE_COUNT};
    text.textLinePointers = malloc(sizeof(TextLine*) * text.maxLineCount);
    if (!text.textLinePointers) {
        fputs(strerror(errno), stderr);
        exit(1);
    }
    for (;;) {
        TextLine* linePointer = readTextLineFrom(f);
        if (linePointer->contentStringLength < 2) {
            break;
        }
        insert(linePointer, &text, text.lineCount + 1);
    }
    return text;
}

void show(Text text) {
    for (int i = -2; i < 3; i++) {
        if ((text.currentLineNumber + i < 1) || (text.lineCount < text.currentLineNumber + i)) {
            continue;
        }
        if (i == 0) {
            printf("%i*%s\n", text.currentLineNumber + i, text.textLinePointers[text.currentLineNumber + i - 1]->contentString);
        } else {
            printf("%i %s\n", text.currentLineNumber + i, text.textLinePointers[text.currentLineNumber + i - 1]->contentString);
        }
    }
}

void appendTo(Text* textPointer) {
    for (;;) {
        TextLine* linePointer = readTextLineFrom(stdin);
        if (linePointer->contentStringLength < 1) {
            fputs("returned from append mode.\n", stdout);
            break;
        }
        insert(linePointer, textPointer, textPointer->lineCount + 1);
    }
}

void replace(Text* textPointer) {
    int currentLineNumber = textPointer->currentLineNumber;
    deleteCurrentLineOf(textPointer);
    for (;;) {
        TextLine* linePointer = readTextLineFrom(stdin);
        if (linePointer->contentStringLength < 1) {
            fputs("returned from append mode.\n", stdout);
            break;
        }
        insert(linePointer, textPointer, textPointer->currentLineNumber);
        textPointer->currentLineNumber++;
    }
    textPointer->currentLineNumber = currentLineNumber;
}

void deleteCurrentLineOf(Text* textPointer) {
    for (int i = textPointer->currentLineNumber - 1; i + 1 < textPointer->lineCount; i++) {
        textPointer->textLinePointers[i] = textPointer->textLinePointers[i + 1];
    }
    textPointer->textLinePointers[textPointer->lineCount] = NULL;
    textPointer->lineCount--;
}

void write(Text text, FILE* f) {
    if (!f) {
        fputs(strerror(errno), stderr);
        exit(1);
    }
    for (int i = 0; i < text.lineCount; i++) {
        fputs(text.textLinePointers[i]->contentString, f);
        fputs("\n", f);
    }
}
