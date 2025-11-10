#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *home_path = getenv("HOME");
    
    if (home_path == NULL) {
        exit(0);
    }

    char *path = malloc(strlen(home_path) + 7 + 1);

    snprintf(path,strlen(home_path) + 7 + 1, "%s/.diary", home_path);

    FILE * f = fopen(path, "r");

    int c;
    while ((c = fgetc(f)) != EOF) {
        putchar(c);
    }

    fclose(f);
}