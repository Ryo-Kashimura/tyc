#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int age;
    int experienced;
    union {
        char memberId[8];
        char* memberPtr;
    };
} Person;

void printPerson(const Person* p, bool useMemberId) {
    if (useMemberId) {
        printf("age: %i, experienced: %i, id: %s\n", p->age, p->experienced, p->memberId);
    } else {
        printf("age: %i, experienced: %i, id: %s\n", p->age, p->experienced, p->memberPtr);
    }
}

int main() {
    Person p0 = {.age = 24, .experienced = 8, .memberId = "Tako M"};
    Person p1 = {.age = 35, .experienced = 1, .memberPtr = "Akiyama Jiro"};
    printPerson(&p0, true);
    printPerson(&p1, false);
    return 0;
}
