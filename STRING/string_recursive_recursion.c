/*
Problem: Write a C program to reverse a string using recursion
*/

#include <stdio.h>
#include <string.h>

void reverse_string(char *str, int start, int end) {
    char temp;
    if (start >= end) return;
    // Swap characters
    temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    
    reverse_string(str, start + 1, end - 1);
}

int main() {
    char str[100];
    // Get the input string from the user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    // Remove newline character if present
    int len = strlen(str);
    
    //remove newline to be reversed in the process
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }
    
    reverse_string(str, 0, len - 1);
    printf("Reversed string: %s\n", str);

    return 0;
}
