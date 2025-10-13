#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint32_t six_middle_bits(uint32_t num) {
    uint32_t mask = 0b111111;
    mask = mask << 13;



    return num & mask;
}

int main(int argc, char *argv[]) {
    printf("0b%032b\n", atoi(argv[1]));
    printf("0b%032b\n", six_middle_bits(atoi(argv[1])));
}