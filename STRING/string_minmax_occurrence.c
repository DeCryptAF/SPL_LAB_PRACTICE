/*
Problem: Write a C program to find maximum and minimum occurring character in a string along with their frequency

Usage:
Take the input. Intialize an array of size 123. The indexes of this arraay represents a ASCII value
For our Alphabets, we have a captial letters in range of 65-90 (A-Z) and for small letters 97-122 (a-z) in ASCII value.

so we will convert our character into a ASCII value and use that as the index for ABD[] and increment it for each character.
This will represent the number of times a character appeared in our string.

Then we take a max and min value and operate on it to find the max values's index and min value's index. This will be later
used to print the result.

fgets (char *str, int n, FILE *stream); // to get input, we use stdin here as it will be manual input.
*/

#include <stdio.h>
#include <string.h>

int abd[123]; // Array to store the frequency of ASCII characters from 0 to 122


int main()
{
    char input[100]; 
    
    printf("Enter a string: ");
    fgets(input, 100, stdin);   
    // gets(input);

    // Iterate through the string
    for (int i = 0; i < strlen(input); i++) 
    {
        int ascii_value = (int)input[i]; // Convert character to ASCII value
        abd[ascii_value]++; // Increment the corresponding index in the array
    }
    int max = 0, min = 1e9;
    int maxindex = 0, minindex = 0;
    char maxchar, minchar;
    // Print the frequency of each character
    for (int i = 65; i < 123; i++) {
        if (abd[i] > 0 && ((i >= 65 && i <= 90) || (i >= 97 && i <= 122)) ) // abd[i] > 0 ensures our character appeared atleast once in the string.
        {
            if (abd[i] > max) max = abd[i], maxchar = (char)i;
            if (abd[i] < min) min = abd[i], minchar = (char)i;
        }
    }
    printf("Max Occurance : %c with a frequency of : %d\n", maxchar, max);
    printf("Min Occurance : %c with a frequency of : %d\n", minchar, min);

    return 0;
}
