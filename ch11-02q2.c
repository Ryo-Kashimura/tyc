#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define INITIAL_LENGTH 4
#define INCREMENT_LENGTH 4

typedef struct {
    int birth;
    int death;
    char name[];
} EMP;

int main() {
    FILE* f = fopen("./ch11-02q2.data", "r");
    if (!f) {
        fprintf(stderr, "%s\n", strerror(errno));
        exit(2);
    }
    EMP** emps = malloc(sizeof(EMP*) * INITIAL_LENGTH);
    int arrayLength = INITIAL_LENGTH;
    for (int last = 0; ;) {
        int birth;
        int death;
        char name[32];
        int ret = fscanf(f, "%*i, %31[^,], %i, %i", name, &birth, &death);
        if (ret == EOF) {
            arrayLength = last;
            break;
        }
        if (last >= arrayLength) {
            EMP** newEmps = realloc(emps, sizeof(EMP*) * (arrayLength + INCREMENT_LENGTH));
            if (!newEmps) {
                fprintf(stderr, "%s\n", strerror(errno));
                break;
            } else {
                emps = newEmps;
                arrayLength += INCREMENT_LENGTH;
            }
        }
        EMP* emp = malloc(sizeof(EMP) + strlen(name) + 1);
        if (!emp) {
            fprintf(stderr, "%s\n", strerror(errno));
            exit(2);
        }
        emp->birth = birth;
        emp->death = death;
        strcpy(emp->name, name);
        emps[last] = emp;
        last++;
    }
    fclose(f);
    for (size_t i = 0; i < (size_t)arrayLength; i++) {
        printf("%-11s %4i - %4i\n", emps[i]->name, emps[i]->birth, emps[i]->death);
    }
    for (size_t i = 0; i < (size_t)arrayLength; i++) {
        free(emps[i]);
    }
    free(emps);
    return 0;
}
