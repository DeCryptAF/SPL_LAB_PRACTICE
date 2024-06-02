/*
Problem: Write a C program to reverse a string using pointer. (Variation - 2)

Usage: 
The main idea is to swap between two characters. But with pointer this time.
          [H][E][L][L][O]    length-5
           ^           ^  
swap-1:   [O][E][L][L][H]
              ^     ^
swap-2:   [O][L][L][E][H]

## Swapping idea
swaping between any two thing requires a temporary vairable. In this case a char.
let's say our (element1) contains the front characters, (element2) contains the back characters.
(temp) is our temporary character.

(element2) gives it's value to (temp). so (temp = element2).
(element2) changes it's value to (element1). so (element2 = element1).
(element1) will now take value of (temp) to complete the swap. so (element1 = temp)
*/

#include <stdio.h> 
#include <string.h> 
int main() 
{ 
    char str[100];
    int len, i; 
    char *begin, *end, ch; 
    printf("Enter a string: ");
    gets(str);
    
    len = strlen(str); 
  
    // starting both ptr from the begining.
    begin = str; 
    end = str; 
  
    //Getting our pointer to the last character of our string. (i < len-1 to skip '\0')
    for (i = 0; i < len - 1; i++) 
        end++;

    /*
    swapping two characters and appraoching the pointer to the middle.
    (i < len/2) because swapping is done between two characters, 
    so two action is done. We only need to travel half of our length.
    If we do (i < len) our string will remain unchanged. So we will never notice the reversing.
    */
    for (i = 0; i < len / 2; i++) { 
        //swap
        ch = *end; 
        *end = *begin; 
        *begin = ch; 
        //ptr change
        begin++; 
        end--; 
    } 
    
    printf("Reverse of the string is: %s", str); 
    return 0; 
}
