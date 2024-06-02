/*
Problem: Write a C program to concatenate a string using pointer.

Usage:
A concatenated string is basically a string-1 + string-2.
If string-1 : HEllO and string-2 : WORLD
it's concatenated string would be : HELLO WORLD

So the key idea is to, dynamically allocate memory for our string of length of [char-size<2bytes> * len(string1 + string2)].
We can also create another char array of length(string1 + string2) and attach out pointer to it.

Then we simply run 2 for-loops, adding both the string.
*/
#include <stdio.h>
#include <string.h>

int main() {
    char str1[256], str2[256], *res;
    int i, j, len;

    //string input
    printf("Enter your first input string:");
    scanf("%s", str1);
    printf("Enter your second input string:");
    scanf("%s",str2);

    //The length of concatenated string 
    len = strlen(str1) + strlen(str2);

    //dynamically allocating memory for a character array (string)
    res = (char *) malloc(sizeof(char) * len);

    //Adding the first string.
    for (i = 0; i < strlen(str1); i++) 
            *(res + i) = *(str1 + i);
    //Adding an extra space between two string
    *(res + i) = ' ';
    i++;
    //Adding the 2nd string
    for (j = 0; j <= strlen(str2); i++, j++) 
            *(res + i) = *(str2 + j);

    printf("Result:\n");
    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);
    printf("Output  : %s\n", res);

    return 0;
}
