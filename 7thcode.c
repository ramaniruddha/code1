#include<stdio.h>

int main() {
    int a[100], n, i;
    int *p;

    p = &a[0];

    printf("Enter the number of array numbers: ");
    scanf("%d", &n);

    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", p);
        p++;
    }

    // Reset the pointer to the beginning of the array
    p = &a[0];

    printf("Array elements using pointer:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", *p);
        p++;
    }

    return 0;
}

