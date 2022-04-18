#include <stdio.h>
/*
Documentation
Name:Sunil M L
Date:17/03/2022
Description: int getword(char *word)
             Create a function named getword.
             Function will receive the string from main
             Function should return the length of the first word.
Test Case 1:
user@emertxe] ./getword
Sample Input: Enter the string : Welcome to Emertxe
Sample Output: You entered Welcome and the length is 7

Test Case 2:
user@emertxe] ./getword
Enter the string : Hello
You entered Hello and the length is 5

Documentation
*/

int getword(char *str); //function prototype
int getword(char *str) //function defination
{
    int len, i = 0; //declaring and intilizing variables
    while (str[i] != '\0') //while loop runs untill the null character
    {
        if (str[i] == ' ') //check the space in the strings
        {
            str[i] = '\0'; //if condition true intlize null character to the str[i]
            break; //exit from the loop
        }
        len++; //increase the value len by 1
        i++; //increase 1 value by 1
    }
    return len; //return len value
}

int main()
{
        int len = 0; //declaring and intilizing len value to 0
	    char str[100]; //declaring character array

		printf("Enter the string : ");
		scanf(" %[^\n]", str);

		len = getword(str); //function call

        printf("You entered %s and the length is %d\n", str, len);
        return 0;
}
