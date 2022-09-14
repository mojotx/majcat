#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include "process.h"
#include "iscomment.h"

#define YEL "\e[33m"
#define BLK "\e[1;30m"
#define OFF "\e[0m"

#define BUFSIZE 65536

void process(const char *fn) {
    FILE *fp;
    char buffer[BUFSIZE] = {0};

    if ((fp = fopen(fn, "r")) == NULL) {
        fprintf(stderr, "Cannot read from %s: %s\n", fn, strerror(errno));
        return;
    }

    // First, count how many lines are in the file
    unsigned long line_count = 0;
    while (fgets(buffer, sizeof(buffer), fp)) {
        line_count++;
    }
    unsigned width = (unsigned) (log10((double) (line_count))) + 1;

    unsigned long int n = 0;
    rewind(fp);
    while (fgets(buffer, sizeof(buffer), fp)) {

        printf(YEL "%*lu:", width, ++n);

        if (is_comment(buffer)) {
            fputs( BLK " ", stdout);
        } else {
            fputs(OFF " ", stdout);
        }

        printf( "%s%s", buffer, OFF);

    }
    if (fclose(fp)) {
        fprintf(stderr, "Cannot close file %s: %s\n", fn, strerror(errno));
    }
}

