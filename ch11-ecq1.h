#include <stdio.h>

typedef struct {
    int contentStringLength;
    int maxContentStringLength;
    char* contentString;
} TextLine;

typedef struct {
    int currentLineNumber;
    int lineCount;
    int maxLineCount;
    TextLine** textLinePointers;
} Text;

void show(Text t);

Text readTextFrom(FILE* f);

void appendTo(Text* textPointer);

void replace(Text* textPointer);

void write(Text t, FILE* f);