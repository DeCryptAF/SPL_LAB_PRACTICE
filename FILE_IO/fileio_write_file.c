/*
Problem: C program to create a file and write something into the file

Usage:
fgets (char *str, int n, FILE *stream); // to get input, we use stdin here as it will be manual input.
fputs ( const char * str, FILE * stream ); // to put the info into the file, we obtained the info using fgets()
*/

#include <stdio.h>

#define MAX_STR_SIZE 1000

int main()
{
    char str[MAX_STR_SIZE];
    FILE * fPtr; //file pointer declared
    fPtr = fopen("Hello.txt", "w"); //file pointer initialized
    if(fPtr == NULL) return 1; //fopen() failed

    printf("Enter message to store in the file : \n");
    
    fgets(str, MAX_STR_SIZE, stdin);
    fputs(str, fPtr);
    fclose(fPtr); //close the file
    return 0;
}
