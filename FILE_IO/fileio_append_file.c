/*
Problem: Write a C program to append content to a file.
*/
#include <stdio.h>

#define MAX_STR_SIZE 1000

int main()
{
    char str[MAX_STR_SIZE];
    FILE * fPtr;
    fPtr = fopen("Hello.txt", "a"); //append mode
    if(fPtr == NULL) return 1;

    printf("Enter text to append : \n");
    fgets(str, MAX_STR_SIZE, stdin);
    fputs(str, fPtr);
    fclose(fPtr);

    //checking the changes by reoppening it (Optional)
    fPtr = fopen("Hello.txt", "r");
    char c;
    do
    {
        c = fgetc(fPtr);
        putchar(c);
    } while (c != EOF);
    

    fclose(fPtr);
    return 0;
}
