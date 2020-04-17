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

Text readTextFrom(FILE* f);

void show(Text t);

void appendTo(Text* textPointer);

void replace(Text* textPointer);

void deleteCurrentLineOf(Text* textPointer);

void write(Text t, FILE* f);
