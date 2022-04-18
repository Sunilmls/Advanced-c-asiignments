#include <stdio.h>
/*
Documentation
Name:Sunil M L
Date:11/03/2022
Description: In mathematics, the Fibonacci numbers or Fibonacci sequence are the numbers in the following integer sequence  0, 1, -1, 2, -3, 5, -8, 13, -21, 34, -55, 89, -144 . . .
             By definition, the first two numbers in the Fibonacci sequence are 0 and 1, each subsequent number is the subtraction of the previous two

Test Case 1 :
Sample Input: Enter a number: -8
Sample Output: 0, 1, -1, 2, -3, 5, -8

Test Case 2:
Sample Input: Enter a number: -10
Sample Output: 0, 1, -1, 2, -3, 5, -8

Test Case 3:
Sample Input: Enter a number: -21
Sample Output: 0, 1, -1, 2, -3, 5, -8, 13, -21

Test Case 4:
Sample Input: Enter a number: 21
Sample Output: Invalid input

Documentation
*/

void negative_fibonacci(int, int, int, int); //function prototype
void negative_fibonacci(int n, int n1, int n2, int n3) //function defination
{
     if ( n1 >= n && n1 <= -n) //if condition check for n1 greater than or equal to n and n1 less than or equal to -n to perform fibonacci series
    {
        if (n1 == 0) //if condition to check for n1 == 0 to omit the ,
        {
        printf("%d", n1);
        }
        else //if condition false print ,
        {
            printf(", %d", n1);
        }
        n3 = n1 - n2; //subtract n1 and n2 and intialize to n3
        n1 = n2; //intialize n2 to n1
        n2 = n3; //intialize n3 to n2
        negative_fibonacci(n, n1, n2, n3); //recursive function calling
    }
}

int main()
{
    int limit; //variable declaration
    
    printf("Enter the limit : ");
    scanf("%d", &limit);
    if ( limit <= 0) //if condition to check the negative number and 0
    {
    negative_fibonacci(limit, 0, 1, 0); //negative_fibonacci function call
    }
    else //if the condition false print Invalid Input 
    {
        printf("Invalid Input");
    }
    return 0;
}
