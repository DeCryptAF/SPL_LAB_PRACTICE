/*
Problem : Write a C program to reverse an array using pointer and struct

Usage:
[Main problem in POINTERS/ptr_reverse_string_2.c]
*/

#include <stdio.h>
#include <string.h>

struct arr {
    char arr[100];
    int len;
    char *end;
    char *start;
    char ch;
} var1;

int main() {
    
    printf("Enter string: ");
    fgets(var1.arr, 100, stdin);
    var1.len = strlen(var1.arr);
    
    var1.start = var1.arr;
    var1.end = var1.arr;
    
    for(int i=0;i<var1.len-1;i++) var1.end++;

    for (int i = 0; i < (var1.len)/2; i++) {
        var1.ch = *var1.end;
        *var1.end = *var1.start;
        *var1.start = var1.ch;
        var1.start++;
        var1.end--;
    }

    printf("Reversed string: %s\n", var1.arr);
    return 0;
}
