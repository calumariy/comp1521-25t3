#include <stdio.h>

union test
{
    int x;
    float y;
};



int main(void) {
    union test test;
    test.x = 0b00111111011111111111111111111111;
    printf("%.20f\n", test.y);
}