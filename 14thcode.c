#include <stdio.h>

int main() {
    int number = 42;
    int *ptr = &number;

    printf("Value: %d\n", *ptr);
    printf("Address: %p\n", ptr);

    return 0;
}

