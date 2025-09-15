#include <stdio.h>

int main(void) {
    int counter = 0;
    while (getchar() != EOF) {
        counter++;
    }

    printf("%d\n", counter);
}
