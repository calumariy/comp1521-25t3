#include <stdio.h>

int main(int argc, char **argv) {
    char *buf = argv[1];
    int counter = 0;
    int i = 0;
    while (buf[i] != '\0') {
        // 1000 0000 -> 80 
        // 0000 0000 -> 00
        if ((buf[i] & 0x80) == 0x00) {
            counter += 1;
        }

        // 1110 0000 -> E0
        // 1100 0000 -> C0
        if ((buf[i] & 0xE0) == 0xC0) {
            counter += 1;
            i += 1;
        }
        // 1111 0000 -> F0
        // 1110 0000 -> E0
        if ((buf[0] & 0xF0) == 0xE0) {
            counter += 1;
            i += 2;
        }

        // 1111 1000 -> F8
        // 1111 0000 -> F0
        if ((buf[0] & 0xF8) == 0xF0) {
            counter += 1;
            i += 3;
        }
        i++;
    }

    printf("there are %d codepoints in the string\n", counter);
}