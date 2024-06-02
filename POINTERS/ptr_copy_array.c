/*
Problem: Write a C program to copy an array to another array using pointer
*/

#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int copiedArr[MAX_SIZE];
    int *ptr = arr;
    int *cptr = copiedArr;
    int size;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    printf("\nEnter %d array elements-\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &(*(arr + i)));
    }

    // Copy elements using pointers
    for (int i = 0; i < size; i++) {
        *(cptr + i) = *(ptr + i);
    }

    // Display the copied array
    printf("\nCopied Array-\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", copiedArr[i]);
    }

    return 0;
}
