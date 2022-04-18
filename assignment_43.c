#include<stdio.h>
/*
Documentation
Name:Sunil M L
Date:26/03/2022
Description: Read a string from the user, find and print all the possible combinations of given string.

Test Case 1:
user@emertxe] ./combinations
Sample Input: Enter a string: abc
Sample Output: All possible combinations of given string :abc
               acb
               bca
               bac
               cab
               cba
               
Test Case 2:
Enter a string: abb
Error: please enter distinct characters.

*/

void combination(char *,int ,int ); //combination function prototype
int my_strlen(char*); //my str_len function prototype
void combination(char *str, int n ,int len) //combination function defination
{
    char temp; //declaring character variable temp
    int i, j; //declaring integer variables
     for(i = 0; i <= len; i++) //for loop to find the repeated characters
        {
            for(j = 0; j <= len; j++) //for loop to compare the characters
            if(i != j) //if condition to exclude the same index
            if(str[i] == str[j]) //if condition to check the character of str[i] to the str[j]
            {
            printf("Error: please enter distinct characters.");
            return; //if condition true return from function
            }
        }
    if ( n == 0) //if condition to print the sentence
        {
          printf("All possible combinations of given string : ");
        }
    if(n == len) //if condition to print the combination of strings
    {
        printf("%s\n", str);
    }
    else //else condition to perform swaping the characters
    {
        for(i = n; i <= len; i++) //for loop to swap the characters
        {
            temp = str[i]; //intilize temp with str[i]
            str[i] = str[n]; //intilize str[i] with the str[n]
            str[n] = temp; //intilize str[n] with the temp
            
            combination(str, n + 1, len); //recursive function call
            
            temp = str[i]; //intilize temp with str[i]
            str[i] = str[n]; //intilize str[i] with the str[n]
            str[n] = temp; //intilize str[n] with the temp
        }
    }
}

int my_strlen(char *str) //function defination
{
    int len = 0; //intilizing and declaring integer variable
    while(str[len] != '\0') //while loop to check the length of the string
    {
        len++; //len value increased by 1
    }
    return len; //return len value
}
int main()
{
        char str[100]; //declaring character array
        int n; //declaring integer variable
        printf("Enter a string: ");
        scanf("%100[^\n]",str);    
        n = my_strlen(str); //my_strlen function call
        combination(str,0,n-1); //combination function call                       
        return 0;
}
