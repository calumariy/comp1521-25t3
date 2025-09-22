// Prints a right - angled triangle of asterisks, 10 rows high.

#include <stdio.h>

int main(void) {
outer_init:
    int i = 1;
outer_cond:
    if (i > 10) {goto outer_end;}
outer_body:
outer_body__inner_init:
    int j = 0;
outer_body__inner_cond:
    if (j >= i) {goto outer_body__inner_end;}
outer_body__inner_body:
    printf("*");
outer_body__inner_incr:
    j++;
    goto    outer_body__inner_cond;
outer_body__inner_end:
    printf("\n");
outer_incr:
    i++;
    goto outer_cond;
outer_end:
    return 0;
}
