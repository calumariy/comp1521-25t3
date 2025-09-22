#include <stdio.h>

int main(void) {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);

    if (x <= 100) {goto print_small_big;}
    if (x >= 1000) {goto print_small_big;}

print_medium:
    printf("medium\n");
    goto    end_label;
print_small_big:
    printf("small/big\n");
end_label:
}
