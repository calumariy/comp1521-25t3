#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        struct stat s;
        if (stat(argv[i], &s)) {
            perror(argv[i]);
        }

        if (s.st_mode & S_IWOTH) {
            chmod(argv[i], s.st_mode ^ S_IWOTH);
        }
    }
}