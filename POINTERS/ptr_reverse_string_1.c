/*
Problem : Write a C program to print a reverse of a string using a pointer
*/
#include <stdio.h>
#include <string.h>
int main()
{
    char *s, str[10];
    int len, i;
    printf("Enter a string: ");
    gets(str);
    s=str;//s = s[0]
    len = strlen(str);
    printf("%d\n", len);
    // we get len = 5
    //  0  1  2  3  4  5
    // [H][E][L][L][O][\0]
    //              ^        so len-1 to skip \0
    //           ^
    //        ^
    //     ^
    //  ^
    // i = 4, s = str[0] -> s+i -> s[4]; so we print O
    // i = 3,                      s[3]; so we pirnt L
    // ... 
    // i = 0,                      s[0]; so we print H
    printf("The reverse of the string is: ");
    for (i = len-1; i >= 0; i--)
    {
        printf("%c", *(s + i));
    }
    return 0;
}
