#include <stdio.h>
/*
Documentation
Name:Sunil M L
Date:17/03/2022
Description: int my_atoi(const char *s)
             The function will recieve a string and covert the number stored in the string into exact integer number.
             Return the number.

Test Case 1 :
Sample Input: Enter a numeric string: 12345
Sample Output: String to integer is 12345

Test Case 2 :
Enter a numeric string: -12345
String to integer is -12345

Test Case 3 :
Enter a numeric string: +12345
String to integer is 12345

Test Case 4 :
Enter a numeric string: +-12345
String to integer is 0

Test Case 5 :
Enter a numeric string: 12345-
String to integer is 12345

Test Case 6 :
Enter a numeric string: abcd12345
String to integer is 0

Test Case 7 :
Enter a numeric string: 12345abcd
String to integer is 12345

Documentation
*/

int my_atoi(const char *); //function prototype
int my_atoi(const char *str) //function defination
{
    int sign = 1, i = 0, res = 0; //declaring and intializing variables
    if (str[0] == '-') //if condition to check negative sign
    {
        sign = -1; //if condition true intialize sign with -1
        i++; //increase the value of i by 1
    }
    else if (str[0] == '+') //if condition to check positive sign
    {
        sign = +1; //if condition true intialize sign with +1
        i++; //increase the value of i by 1
    }
    for (i ; str[i] != '\0'; ++i) //if condition to check the remaining characters
    {
        if (str[i] >= '0' && str[i] <= '9') //if condition to check the character between 0 and 9
        {
        res = res * 10 + str[i] - '0'; //if the condition true multiply res with 10 and adding str[i] is subtract from '0'
        }
        else //else condition to check other character
        {
            res = res | 0; //if condition false perform res bitwise operation with 0
            break; //exit from the loop
        }
    }
    return sign * res; //return the multiply of res with sign
}

int main()
{
    char str[20]; //character array declaration
    
    printf("Enter a numeric string : ");
    scanf("%s", str);
    
    printf("String to integer is %d\n", my_atoi(str)); //function calling and print the return value
    return 0;
}
