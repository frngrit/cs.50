#include <stdio.h>
// #include <cs50.h>

int main()
{
    // Pointer to an integer
    int *p;

    // Pointer to an array of 5 integers
    int(*ptr)[5];
    int arr[5];

    // Points to 0th element of the arr.
    p = arr;

    // Points to the whole array arr.
    ptr = &arr;

    printf("p = %p, ptr = %p, arr = %p\n", p, ptr, arr);

    p++;

    printf("p = %p, ptr = %p, arr = %p\n", p, ptr[1], &arr[1]);

    return 0;
}