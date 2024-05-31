/*
Problem: Write a C program to count characters, words and lines in a text file

Usage:
fgetc(FILE *pointer) // fgetc() is used to obtain input from a file single character at a time. It returns the character present at position indicated by file pointer.
If pointer is at end of file or if an error occurs, EOF file is returned by this function. 
*/
#include <stdio.h>

#define MAX_STR_SIZE 1000

int main()
{
    char str[MAX_STR_SIZE];
    FILE * fPtr;
    fPtr = fopen("Hello.txt", "r"); // in read mode
    if(fPtr == NULL) return 1; //fopen() failed
    
    char c;
    int characters = 0, words = 0, lines = 0;
    
    while ((c = fgetc(fPtr)) !=EOF) //checking if our fgetc() is giving a EOF or not. If it is, it indicates end of our scanning.
    {
        characters++;
        if (c == '\n' || c == '\0') lines++; // condition for a new line
        if (c == ' ' || c == '\t' || c == '\n' || c == '\0') words++; // condition for a new word. 
    }
  
    if (characters > 0) words++, lines++; // append value for the last word. As it hits End of file (EOF), the last word is left out along with a line.

    printf("Total characters : %d , words : %d , lines : %d\n", characters, words, lines);
    fclose(fPtr);
    return 0;
}

