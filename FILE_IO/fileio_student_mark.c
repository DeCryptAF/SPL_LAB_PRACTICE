/*
Problem : Write a C program to read name and marks of n number of students and store them in a file.

Usage : 
fprintf( FILE * stream, const char * format, ... ); for writing in the file in a specific format.
*/


#include <stdio.h>

#define MAX_STR_SIZE 1000

int main()
{
    char name[MAX_STR_SIZE]; //student name string
    FILE *fptr;
    fptr = fopen("Hello.txt", "w");

    if (fptr == NULL) return 1; //fopen() failed 
    
    int n, mark;
    printf("Enter the number of students : \n");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("Enter the name of the student : \n");
        scanf("%s", name);
        printf("Enter the mark : \n");
        scanf("%d", &mark);
        fprintf(fptr, "%d. %s : %d\n", i, name, mark); //writing into the file. 
    }
    fclose(fptr);
    return 0;
}
