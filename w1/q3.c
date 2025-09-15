#include <stdio.h>

int *get_num_ptr(void);
int x = 42;

int main(void) {
    int *num = get_num_ptr();
    printf("%d\n", *num);
}

int *get_num_ptr(void) {
    return &x;
}
