/*
Problem: Print the sum of Fibonacci number upto n.
*/

#include <stdio.h>

int main() {
    int n, t1 = 0, t2 = 1, nextTerm;
    printf("Value of n for Fibonacci : ");
    scanf("%d", &n);
    printf("Fibonacci Series: ");
    printf("%d %d ", t1, t2);
  
    //The base case of a fibonacci series start from 0 1 (0 + 1)
    int sum = t1 + t2;
  
    // starting from i = 3 because we already have first 2 elements
    for (int i = 3; i <= n; ++i) {
        nextTerm = t1 + t2;
        sum += nextTerm;
        printf("%d ", nextTerm);
        t1 = t2;
        t2 = nextTerm;
    }
  
    printf("\nSum: %d\n", sum);
    return 0;
}
