/*
Problem: Write a C program to replace a word in a file 

Usage:
feof(FILE* stream); // The feof() function is used to check whether the file pointer to a stream is pointing to the end of the file or not. 
                        It returns a non-zero value if the end is reached, otherwise, it returns 0.

strstr (const char *s1, const char *s2); // finds the first occurrence of the string s2 in the string s1. 
                                    The process of matching does not include the terminating null-characters(‘\0’), but function stops there. 
                                    This function returns a pointer point to the first character of the found s2 in s1 otherwise a null pointer 
                                    if s2 is not present in s1. If s2 points to an empty string, s1 is returned.
*/

#include <stdio.h>
#include <string.h>

#define MAX_STR_SIZE 1000

int main()
{
    //All the necessary declarations
    FILE *OGFILE;
    FILE *COPYFILE;

    char old_word[MAX_STR_SIZE];
    char new_word[MAX_STR_SIZE];

    char fileName[] = "Hello.txt";
    char tempFileName[] = "Temp.txt";
    
    // Prompt for the word and what to be replaced
    printf("Enter the word to replace : ");
    scanf("%s", old_word);
    printf("Replace by new word : ");
    scanf("%s", new_word);
    
    /*
    OGFILE (original file is simply in read mode, we don't want to write anything in it.)
    COPYFILE (It's in write mode, because we want to rewrite what the OGFILE has along with replaced word)
    */
    OGFILE = fopen(fileName, "r");
    COPYFILE = fopen(tempFileName, "w");

    if (OGFILE == NULL || COPYFILE == NULL) return 1; //fopen() failed

    /* 
    Temporary variables that will be used to do the operation.
    The key idea is to, use ptr2 for the line we will read in the OGFILE
    ptr1 will be keep track where our occurance of the (word to be replaced) is.

    We want to print everyting before the occurance of our (word to be replaced) in our COPYFILE.
    Then instead of (word to be replaced) we print the NEW WORD.
    Then simply we will print the rest of the file.
    */
    char str[MAX_STR_SIZE];
    char *ptr1, *ptr2;

    while (!feof(OGFILE)) // till we don't hit EOF for the OGFILE
    {
        fgets(str, MAX_STR_SIZE, OGFILE); //read line by line
        
        if (strstr(str, old_word)) //check if word present, else will print the whole line in COPYFILE.
        {
            ptr2 = str; // getting the ptr for our line that we read

            /*
            while we still have the occurance of our old word in the line we read,
            we will keep the operation
            */
            while (ptr1 = strstr(ptr2, old_word)) 
            {
                /*
                letters before the (word to be replaced) being printed.
                ptr2 will keep printing each characters till it hits our (word to be replaced).
                */
                while (ptr2 != ptr1)
                {
                    fputc(*ptr2, COPYFILE);
                    ptr2++;
                }
                
                ptr1 = ptr1 + strlen(new_word); //skip the (word to be replaced)
                
                fprintf(COPYFILE, "%s", new_word); // instead print the new word
                
                ptr2 = ptr1; // reset the position after the skip. We continue from here onwards.
            }
            
            /*
            print everything else after the (word to be replaced)
            */
            while (*ptr2 != '\0')
            {
                fputc(*ptr2, COPYFILE);
                ptr2++;
            }
        }
        else 
        {
            /*
            current scanned line doesn't have any word to be
            replaced. So print everything. 
            */
            fputs(str, COPYFILE);
        }
    }

    //closing the file
    fclose(OGFILE);
    fclose(COPYFILE);

    remove(fileName); //remove Original file
    rename(tempFileName, fileName); //rename temp file to original name
    return 0;
}
