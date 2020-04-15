#include "ch12-ecq1_syntaxtree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>

Cell* generateSyntaxTree() {
    char ch = getchar();
    if ((ch == EOF) || (ch == ')')) {
        return NULL;
    }
    Cell* cell = malloc(sizeof(Cell));
    if (!cell) {
        fputs(strerror(errno), stderr);
        exit(1);
    }
    Node *car, *cdr;
    car = malloc(sizeof(Node));
    cdr = malloc(sizeof(Node));
    if (!car || !cdr) {
        fputs(strerror(errno), stderr);
        exit(1);
    }
    cell->car = car;
    cell->cdr = cdr;
    if (ch == '(') {
        car->valueIsNumeric = cdr->valueIsNumeric = false;
        car->nextCell = generateSyntaxTree();
        cdr->nextCell = generateSyntaxTree();
    } else if (('0' <= ch) && (ch <= '9')) {
        char digits[11];
        digits[0] = ch;
        digits[10] = '\0';
        for (int i = 1; i < 10; i++) {
            ch = getchar();
            if (('0' <= ch) && (ch <= '9')) {
                digits[i] = ch;
            } else {
                if (ungetc(ch, stdin) == EOF) {
                    fputs(strerror(errno), stderr);
                    exit(1);
                }
            }
        }
        car->value = malloc(sizeof(Value));
        if (!(car->value)) {
            fputs(strerror(errno), stderr);
            exit(1);
        }
        car->value->number = atoi(digits);
        car->valueIsNumeric = true;
        cdr->valueIsNumeric = false;
        cdr->nextCell = generateSyntaxTree();
    } else if ((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/')) {
        car->value = malloc(sizeof(Value));
        if (!(car->value)) {
            fputs(strerror(errno), stderr);
            exit(1);
        }
        car->value->symbol = ch;
        car->valueIsNumeric = cdr->valueIsNumeric = false;
        cdr->nextCell = generateSyntaxTree();
    } else {
        cell = generateSyntaxTree();
    }
    return cell;
}

int computedFrom(Cell* cell) {
    if (!cell) {
        fputs("syntax error.\n", stderr);
        exit(1);
    }
    if (!(cell->car->value)) {
        return computedFrom(cell->car->nextCell);
    }
    if (cell->car->valueIsNumeric) {
        return cell->car->value->number;
    } else {
        int result = computedFrom(cell->cdr->nextCell);
        while (cell->cdr->nextCell->cdr->nextCell) {
            if (cell->car->value->symbol == '+') {
                result += computedFrom(cell->cdr->nextCell->cdr->nextCell);
            } else if (cell->car->value->symbol == '-') {
                result -= computedFrom(cell->cdr->nextCell->cdr->nextCell);
            } else if (cell->car->value->symbol == '*') {
                result *= computedFrom(cell->cdr->nextCell->cdr->nextCell);
            } else if (cell->car->value->symbol == '/') {
                result /= computedFrom(cell->cdr->nextCell->cdr->nextCell);
            } else {
                fputs("syntax error.\n", stderr);
                exit(1);
            }
            if (cell->cdr->nextCell->cdr->nextCell->car->value) {
                if (cell->cdr->nextCell->cdr->nextCell->car->valueIsNumeric) {
                    cell->cdr->nextCell->cdr->nextCell->car->value->number = result;
                }
            }
            cell->cdr->nextCell = cell->cdr->nextCell->cdr->nextCell;
        }
        return result;
    }
}

void showSyntaxTreeOfInner(const Cell* cell) {
    if (!cell) {
        return;
    }
    printf("(");
    showSyntaxTreeOfInner(cell->car->nextCell);
    if (cell->car->value) {
        if (cell->car->valueIsNumeric) {
            printf(" %i", cell->car->value->number);
        } else {
            printf("%c ", cell->car->value->symbol);
        }
    }
    showSyntaxTreeOfInner(cell->cdr->nextCell);
    printf(")");
}

void showSyntaxTreeOf(const Cell* cell) {
    showSyntaxTreeOfInner(cell);
    printf("\n");
}
