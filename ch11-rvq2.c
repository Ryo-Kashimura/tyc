#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE* previousResult;
    char buffer[9];
    int previousNumber = 0;
    if (argc < 2) {
        previousResult = fopen("./ch11-rvq2_last-result.data", "rb");
        if (previousResult) {
            if (fread(&buffer, 9, 1, previousResult)) {
                previousNumber = atoi(buffer);
            }
        }
    } else {
        previousNumber = atoi(argv[1]);
    }
    fprintf(stdout, "previousNumber: %i\n", previousNumber);
    if (previousResult) {
        if (fclose(previousResult)) {
            fprintf(stderr, "%s\n", strerror(errno));
            return 1;
        }
    }
    fprintf(stdout, "previousNumber: %i\n", previousNumber);
    int currentNumber = previousNumber + 10;
    sprintf(buffer, "%i", currentNumber);
    FILE* currentResult = fopen("./ch11-rvq2_last-result.data", "wb");
    if (!fwrite(buffer, 9, 1, currentResult)) {
        fprintf(stderr, "%s\n", strerror(errno));
        return 1;
    }
    if (fclose(currentResult)) {
        fprintf(stderr, "%s\n", strerror(errno));
        return 1;
    }
    fprintf(stdout, "%i\n", currentNumber);
    return 0;
}
