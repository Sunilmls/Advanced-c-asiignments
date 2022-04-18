#include <stdio.h>
/*
Documentation
Name:Sunil M L
Date:21/03/2022
Description: Read a string from the user. Check whether the string is Pangram or not
             A pangram is a sentence containing every letter in the English Alphabet.
             Example 1 : "The quick brown fox jumps over the lazy dog ” is a Pangram [Contains all the characters from ‘a’ to ‘z’] 
             Example 2: “The quick brown fox jumps over the dog” is not a Pangram [Doesn’t contain all the characters from ‘a’ to ‘z’, as ‘l’, ‘z’, ‘y’ are missing]

Test Case 1:
Sample Input: Enter the string: The quick brown fox jumps over the lazy dog
Sample Output: The Entered String is a Pangram String

Test Case 2:
Enter the string: The quick brown fox jumps over the dog
The Entered String is not a Pangram String

*/
int pangram(char *); //function prototype
int pangram(char *str) //function defination
{
    int i, count = 0; //declaring and intilizing variables
    int arr[26] = {0}; //declare and initilize intiger array 
    for(i = 0; str[i] != '\0'; i++) //for loop to check the all characters
    {
        if('a' <= str[i] && str[i] <= 'z') //if condition to check the characters are in between a to z
        {
            count = count + !arr[str[i] - 'a']; //add count value with ![str[i] - 'a'] and store in count
            arr[str[i] - 'a'] = 1; //make arr[str[i] - 'a'] to 1 
        }
        else if('A' <= str[i] && str[i] <= 'Z')  //else if condition to check the characters are in between A to Z
        {
            count = count + !arr[str[i] - 'A']; //add count value with ![str[i] - 'A'] and store in count
            arr[str[i] - 'A'] = 1; //make arr[str[i] - 'a'] to 1 
        }
    }
     return count; //return count value
}
 
int main()
{
    char str[100]; //declaring character array
    int total; //declaring integer variable
    printf("Enter the String:\n");
    fgets(str, 100, stdin); //read the string
    total = pangram(str); //function call
    
    if(total == 26) //if condition to check the return value is 26
    {
        printf("The Entered String is a Pangram String");
    }
    else //else condition for total not equal to 26 
    {
        printf("The Entered String is not a Pangram String");
    }
    return 0;
}
