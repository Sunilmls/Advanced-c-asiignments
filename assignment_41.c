#include <stdio.h>
/*
Documentation
Name:Sunil M L
Date:21/03/2022
Description: Read two strings s1 and s2 from user.
             Remove the characters in s1 that matches with s2.
             Input string:
              string 1: Dennis Ritchie
              string 2: Linux
            Output String:
            After squeeze s1: Des Rtche
            Should not use extra array or the pointer

Test Case 1:
user@emertxe] ./squeeze
Sample Input: Enter s1 : Dennis Ritchie
              Enter s2 : Linux
Sample Output: After squeeze s1 : Des Rtche

Test Case 2:
user@emertxe] ./squeeze
Enter s1 : Welcome
Enter s2 : Emertxe
After squeeze s1 : Wlco

*/

void squeeze(char*, char*); //function prototype
void squeeze(char *str1, char *str2) //function defination
{
    int i = 0, j, k; //declaring and intilizing the variables
    while(str2[i] != '\0') //while loop for checking the character of str2[j]
    {
        j = 0; //intilize j with 0
        while(str1[j] != '\0') //while loop for checking the characters of str1[j]
        {
            if (str2[i] == str1[j]) //if condition to check the character of str2[i] with str1[j]
            {
                str1[j] = str1[j + 1]; //intilize str[j] with the str[j + 1]
                k = j + 1; //intilize k with j + 1
                while(str1[k] != '\0') //while loop to shift the characters
                {
                    str1[k] = str1[k + 1]; //intilize str[k] with str[k + 1]
                    k++; //increase k value by 1
                }
            }
            j++; //increase j value by 1
        }
        i++; //increase i value by 1
    }
}

int main()
{
    char str1[30], str2[30]; //declaring 2 character array
    
    printf("Enter string1: ");
    scanf("%[^\n]", str1);
    

    printf("Enter string2: ");
    scanf(" %[^\n]", str2);
    
    squeeze(str1, str2); //function call
    
    printf("After squeeze s1 : %s\n", str1);
    return 0;
    
}
