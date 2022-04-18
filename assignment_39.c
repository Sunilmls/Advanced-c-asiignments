#include <stdio.h>
/*
Documentation
Name:Sunil M L
Date:19/03/2022
Description: Read a string from user.
             Implement using recursive function without using any loops
             Do not print character by character.

Test Case 1:
user@emertxe] ./str_rev
Sample Input: Enter a string : Hello World
Sample Output: Reverse string is : dlroW olleH

Test Case 2:
user@emertxe] ./str_rev
Enter a string : EMERTXE
Reverse string is : EXTREME

*/

void reverse_recursive(char *str, int ind, int len); //function prototype
void reverse_recursive(char *str, int ind, int len) //function defination
{
    int j; //declaring variable
    char temp; //declaring character variable
    if (ind == 0) //if condition to find the length of the string
    {
    while (str[len] != '\0') //while loop runs untill get the null character
    {
        len++; //if condition true increased len value by 1
    }
       len = len - 1; //len intilized by len - 1
    }   
        j = len - ind; //intilized j value with len - ind
        temp = str[ind]; //intilized temp value with the str[ind]
        str[ind] = str[j]; //intilized str[ind] with str[j]
        str[j] = temp; //intilized str[j] with temp
        if(ind != len / 2) //if condition to call the recursive function
        {
        reverse_recursive(str, ind + 1, len); //recursive function call
        }
}

int main()
{
    char str[30]; //declaring character array
    
    printf("Enter any string : ");
    scanf("%[^\n]", str);
    
    reverse_recursive(str, 0, 0); //function call
    
    printf("Reversed string is %s\n", str);
    return 0;
}
