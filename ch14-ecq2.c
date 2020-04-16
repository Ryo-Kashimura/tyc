#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRINT_DATETIME(date, time) fprintf(stdout, "%04i/%02i/%02i %s\n", yearDigitsOf(date), monthDigitsOf(date), dayDigitsOf(date), time)

int yearDigitsOf(const char* date) {
    char yearString[5];
    yearString[4] = '\0';
    strncpy(yearString, date + 7, 4);
    return atoi(yearString);
}

int monthDigitsOf(const char* date) {
    char months[12][4] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    for (int _monthDigits = 1; _monthDigits <= 12; _monthDigits++) {
        char month[4];
        month[3] = '\0';
        strncpy(month, date, 3);
        if (!strcmp(month, months[_monthDigits])) {
            return _monthDigits + 1;
        }
    }
    return 0;
}

int dayDigitsOf(const char* date) {
    char dayString[3];
    dayString[2] = '\0';
    strncpy(dayString, date + 4, 2);
    return atoi(dayString);
}

int main() {
    char* date = __DATE__;
    char* time = __TIME__;
    PRINT_DATETIME(__DATE__, __TIME__);
    return 0;
}
