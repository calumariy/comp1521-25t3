#include <stdio.h>
#include <stdint.h>

int main(void) {
    uint16_t a = 0x5555, b = 0xAAAA, c = 0x0001;

    printf("0b%b\n", a | b);
    printf("0b%b\n", b);
    printf("0b%b\n", c);
}