#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Error: incorrect arguments\n");
        exit(1);
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        perror(argv[1]);
        exit(1);
    }

    char buffer[1024];

    fgets(buffer, sizeof(buffer) - 1, f);

    fclose(f);

    fputs(buffer, stdout);
}