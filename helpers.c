#include "helpers.h"

#define DELIMS ", "
#define LINE_LEN 80

void readRestOfLine() {
    int ch;
    while (ch = getc(stdin), ch != EOF && ch != '\n') { } /* Gobble each character. */

    /* Reset the error status of the stream. */
    clearerr(stdin);
}

int validateNumber() {

    char line[LINE_LEN + EXTRA_SPACES];
    char *end;
    int input;

    do {
        printf("Please enter your choice:");
        fgets(line, LINE_LEN + EXTRA_SPACES, stdin);

        if (line[strlen(line) - 1] != '\n') {
            readRestOfLine();
            continue;
        }

        line[strlen(line) - 1] = 0;

        input = strtol(line, &end, 0);
    }

    while(*end);

    return input;

}

char * validateString(){
    char line[LINE_LEN + EXTRA_SPACES];
    char *end = malloc(strlen(line) + EXTRA_SPACES);

    printf("Please enter your choice:");
    fgets(line, LINE_LEN + EXTRA_SPACES, stdin);

    if(line[strlen(line)-1] != '\n'){
        readRestOfLine();
    }

    line[strlen(line) - 1] = 0;
    line[strcspn(line, "\n")] = '\0';
    strcpy(end, line);

    return end;

}

