#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void) {
    FILE *f;

    f = fopen("/etc/shadow", "r");
    if (f == NULL) {
        perror("error logic");
        exit(1);
    }
    // DO STUFF

    fclose(f);
}