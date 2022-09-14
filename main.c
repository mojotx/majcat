#include <stdlib.h>
#include "process.h"

int main(int argc, char *argv[]) {
    // iterate over each filename specified on the command line
    for (int i=1; i<argc; i++) {
        const char *fn = argv[i];
        process(fn);
    }
    return EXIT_SUCCESS;
}
