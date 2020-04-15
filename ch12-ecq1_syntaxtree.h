#include <stdbool.h>

typedef union {
    int number;
    char symbol;
} Value;

struct cell;

typedef struct node {
    Value* value;
    bool valueIsNumeric;
    struct cell* nextCell;
} Node;

typedef struct cell {
    Node* car;
    Node* cdr;
} Cell;

Cell* generateSyntaxTree();

void showSyntaxTreeOf(const Cell* cell);

int computedFrom(Cell* cell);