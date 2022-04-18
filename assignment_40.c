#include <stdio.h>
/*
Documentation
Name:Sunil M L
Date:24/03/2022
Description: Read string1 and string2 from user.
             Call my_strtok (string1, string2);
             Should treat string2 as delimitter in string1 and should return 1 st field.
             If you call again my_strtok (NULL, string2), it should return second field in string1 treating string2 as delimitter.

Test Case 1:
user@emertxe] ./my_strtok
Sample Input: Enter string1 : Bangalore;;::---Chennai:;Kolkata:;Delhi:-:Mumbai
              Enter string2 : ;./-:
Sample Output: Tokens :
               Bangalore
               Chennai
               Kolkata
               Delhi
               Mumbai

Test Case 2:
user@emertxe] ./my_strtok
Enter string1 : -;Bangalore;;::---Chennai:;Kolkata:;Delhi:-
Enter string2 : ;./-:
Tokens :
Bangalore
Chennai
Kolkata
Delhi

*/

int check_delim(char , char *); //check_delim function prototype
char *my_strtok(char * str, char *delim); //*my_strtok function prototype
int check_delim(char str, char *delim) //check_delim function defination
{
    while(*delim != '\0') // //while loop to check the string and delim
    {
        if(str == *delim) //if condition to string character equal to delim
        {
        return 1; //condition true return 1
        }
        delim++; //increase delim address by 1
    }
    return 0; //return 0
}
char *my_strtok(char *str, char *delim) //*my_strtok function defination
{
    static char *str1; //declaring static char pointer
    char *ret; //declaring char pointer
    if(!str) //if condition to check string character null
    {
        str = str1; //if condiition true store address of the str1 to the str
    }
    while(str) //while loop running untill the delim 
    {
        if(check_delim(*str, delim)) //function calling in if condition to check character is delim or not
        {
            str++; //increase the str address by 1
            continue; //continue to skip the addresses
        }
        if(*str == '\0') //if condition to check null in string
        {
            return NULL; //if condition true return null
        }
        break; //exit from the loop
    }
    ret = str; //assign str address to the ret
    while(1) //while loop to check the string after the delimeter
    {
        if(*str == '\0') //if condition to check null in string
        {
            str1 = str; //assign str address to the str1
            return ret; //return ret 
        }
        if(check_delim(*str, delim)) //function calling in if condition to check character is delim or not
        {
            *str = '\0'; //assign null character to the str
            str1 = str + 1; //store address of str + 1 to the str1
            return ret; //return ret
        }
        str++; //increase str addess by 1
    }
}

int main()
{
    char str[50], delim[50]; //declaring character array
    
    printf("Enter the string  : ");
    scanf("%s", str);
     __fpurge(stdout); //clear the buffer
 
    printf("Enter the delimeter : ");
    scanf("\n%s", delim);
    __fpurge(stdout); //clear the buffer
    
    char *token = my_strtok(str, delim); //function call
    printf("Tokens :\n");
    
    while (token) //while loop to print the string
    {
        printf("%s\n", token);
        token = my_strtok(NULL, delim); //function call
    }
    return 0;
}
