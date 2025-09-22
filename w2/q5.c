#include <stdio.h>

#define SQUARE_MAX 46340

int main(void) {
    int x, y;

    printf("Enter a number: ");
    scanf("%d", &x);


    
    if (x > SQUARE_MAX) {
        goto error_code;
    } else {
        goto square_code;
    }

error_code:
    printf("square too big for 32 bits\n");

    goto epilogue;


square_code:
    y = x * x;
    printf("%d\n", y);

epilogue:
    return 0;
}