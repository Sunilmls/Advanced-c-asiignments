#include <stdio.h>
/*
Documentation
Name:Sunil M L
Date:18/03/2022
Description: int itoa(int n, char *s)
             Convert integer n into a string and store the string in s.
             Return the length of string from the function.

Test Case 1:
user@emertxe] ./itoa
Sample Input: Enter the number : 1234
Sample Output: Integer to string is 1234

Test Case 2:
user@emertxe] ./itoa
Enter the number : -1234
Integer to string is -1234

Test Case 3:
user@emertxe] ./itoa
Enter the number : +1234
Integer to string is 1234

Test Case 4:
user@emertxe] ./itoa
Enter the number : a1234
Integer to string is 0

Documentation
*/

int itoa(int num, char *str); //function prototype
int itoa(int num, char *str) //function defination
{
    int mod = 0, sum = 0, i = 0; //variable declaration
    if (num >= - 123456 && num <= 123456) //if condition to check integer 
    {
    if (num < 0) //if condition to check negative number
    {
        str[0] = '-'; //intialize - to str[0]
        num = - num;//intilize num with -num
        i++; //i value increased by 1
    }
    while(num != 0)  //while loop reverse the number
    {
     mod = num % 10 ; //intilize mod with num % 10
     sum = sum * 10 + mod; //initilize sum with sum * 10 and add to the mod
     num = num / 10; //intilize num with num divide by 10
    }
    while(sum != 0) //while loop to store ascii values
    {
        str[i++] = sum % 10 + 48; //store sum % 10 add with 48 to str[i]
        sum = sum / 10; //intilize sum with sum sum divide 10
    }
    str[i] = '\0';
    }
    else //else condition to check non integer value
    {
    str[0] = '0'; //intilize 0 to str[0]
    str[1] = '\0'; //intialize null value to the str[i + 1]
    }
}

int main()
{
    int num; //declaring num variable
    char str[10]; //declaring character array
    
    printf("Enter the number: ");
    scanf("%d", &num);
    itoa(num, str); //function call
    printf("Integer to string is %s", str);
    return 0;
}
