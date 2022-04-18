#include <stdio.h>
/*
Documentation
Name:Sunil M L
Date:24/03/2022
Description: Suppose k = 3 (say taking 3 distinct characters ).
             Let 3 distinct characters be a , b, c.
             Suppose ‘n’ is the string length to be formed using ‘k’ distinct words.
             Let n be 6
             The string should be formed in such a way that there should not be any consecutive repetitions of the strings.

Test Case 1:
user@emertxe] ./nrps
Sample Input: Enter the number characters C : 3
              Enter the Length of the string N : 6
              Enter 3 distinct characters : a b c
Sample Output: Possible NRPS is abcbca

Test Case 2:
Enter the number characters C : 3
Enter the Length of the string N : 7
Enter 3 distinct characters : a b a
Error : Enter distinct characters
*/

void nrps(char *, int, int); //function prototype
void nrps(char *str, int C, int N) //function defination
{
    char str1[100]; //declaring character to store characters
    int i = 0, j, cnt = 0, k = 0, temp; //intilizing and declaring integer variables
    while(str[i] != '\0') //while loop to find possible combination of string
    {
        j = 0; //intilize j with 0
        while(str[j] != '\0') //while loop for check characters
        {
            if( i != j) //if condition to exclude the same index
            {
                if(str[i] == str[j]) //if condition to find non distant character
                {
                    printf("Error : Enter distinct characters");
                    return; //if find any same character return from the function
                }
            }
            temp = str[i]; //store temp with str[i]
            str[i] = str[j]; //store str[i] with str[j] value
            str[j] = temp; //store str[j] with temp value
            k = 0; //intilize k with 0
            while(str[k] != '\0') //while loop to store the character to another array 
            {
                str1[cnt] = str[k]; //store str[cnt] with str[k] value
                k++; //increase k value by 1
                cnt++; //increase cnt value by 1
            }
            j++; //increase j value by 1
        }
        i++; //increase i value by 1
    }
    printf("Possible NRPS is ");
    if (cnt >= N) //if condition to print possible nrps
    {
        str1[N] = '\0'; //if condition true set str[N] as NULL
        printf("%s", str1);
    }
    else //else condition to print possibe nrps
    { 
        k = 0; //intilize k with 0
        while(cnt <= N) //while loop for check characters less than or equal to N
        {
            str1[cnt] = str[k]; //store str1[cnt] with str[k] value
            k++; //increase k value by 1
            cnt++; //increase cnt value by 1
        }
        str1[N] = '\0'; // set str[N] as NULL
        printf("%s", str1);
    }
}

int main()
{
    char str[100]; //declaring character array
    int C, N; //declaring integer variables
    printf("Enter the number characters C : ");
    scanf("%d", &C);
    printf("Enter the Length of the string N : ");
    scanf("%d", &N);
    if(N >= C) //if condition to check N is greter than or equal to C
    {
    printf("Enter %d distinct characters : ", C);
    scanf(" %[^\n]", str);
    
        nrps(str, C, N); //if condition true call the function
    }
    else //if condition false print error message
    {
        printf("Error: Pass more than %d characters", C);
    }
    return 0;
}
