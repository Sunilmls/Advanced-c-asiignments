#include <stdio.h>
/*
Documentation
Name:Sunil M L
Date:18/03/2022
Description: Read a string from user.
             Implement using loops.
             Do not print character by character.

Test Case 1:
user@emertxe] ./str_rev
Sample Input: Enter a string : Hello World
Sample output: Reverse string is : dlroW olleH

Test Case 2:
user@emertxe] ./str_rev
Enter a string : EMERTXE
Reverse string is : EXTREME
Documentation
*/

void reverse_iterative(char *str); //function prototype
void reverse_iterative(char *str) //function defination
{
    int i = 0, j = 0, temp, len = 0; //declaring and intilizing variable
    while(str[len] != '\0') //while loop to find the length of the string
    {
        len++; //len value increase by 1
    }
    j = len - 1; //intilize j with len - 1
    for ( i = 0; i < len / 2; i++) //for loop o reverse the string
    {
        temp = str[i]; //initlize temp with str[i]
        str[i] = str[j]; //intilize str[i] with str[j]
        str[j] = temp; //intilize str[j] with temp
        j--; //j value decrease by 1
    }
}
int main()
{
    char str[30]; //declaring character array
    
    printf("Enter any string : ");
    scanf("%[^\n]", str);
    
    reverse_iterative(str); //function call
    
    printf("Reversed string is %s\n", str);
    return 0;
}
