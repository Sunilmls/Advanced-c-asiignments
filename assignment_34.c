#include <stdio.h>
/*
Documentation
Name:Sunil M L
Date:20/03/2022
Description: Input string:
             Pointers         are      sharp           knives.
             Output String:
             Pointers are sharp knives.
             Blank can be spaces or tabs. (replace with single space).

Test Case 1:
user@emertxe] ./remove_multi_space
Sample Input: Enter the string with more spaces in between two words
              Pointers     are               sharp     knives.
Sample Output: Pointers are sharp knives.

Test Case 2:
user@emertxe] ./remove_multi_space
Enter the string with more spaces in between two words
Welcome                to Emertxe
Welcome to Emertxe

Test Case 3:
user@emertxe] ./remove_multi_space
Enter the string with more spaces in between two words
Welcome to Emertxe
Welcome to Emertxe

Documentation
*/

void replace_blank(char *); //function prototype
void replace_blank(char *str) //function defination
{
    int i = 1, j, cnt; //declaring and initilizing variable
    while (str[i] != '\0') //while loop run untill the null character
    {
        cnt = 0; //set count as 0
        if (str[i] == ' ' && str[i - 1] == ' ') //if condition to check the present and previous character
        {
            str[i] = str[i + 1]; //if the condition true intlize str[i + 1] to the str[i]
            j = i + 1; //intilize i to the j
            while (str[j] != '\0') //while loop to check null character
            {
                str[j] = str[j + 1]; //intilize str[j + 1] to the str[j]
                j++; //increase j value by 1
            }
            str[j] = '\0'; //intilize null character to the str[j]
            cnt = 1; //set cnt as 1
        }
        if (cnt == 0) //if condition to check cnt value for increasing the character
        {
            i++; //if condition true increase i value by 1
        }
    }
}

int main()
{
    char str[100]; //declaring character array 
    
    scanf("%[^\n]", str);
    
    replace_blank(str); //function call
    
    printf("%s\n", str);
    return 0;
}
