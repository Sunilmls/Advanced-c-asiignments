#include <stdio.h>
#include <stdlib.h>
/*
Documentation
Name:Sunil M L
Date:04/04/2022
Description: Read the N name from the user
             Sort it in alphabetical order
             Use 1st dynamic and 2nd static. Char (*name)[32]
             No.of names should be dynamic and no.of characters should be static.
             Allocate the memory dynamically for no.of names.

Sample execution: -
Test Case 1:
user@emertxe] ./sort

Sample Input: Enter the size: 5
              Enter the 5 names of length max 32 characters in each
              [0] -> Delhi
              [1] -> Agra
              [2] -> Kolkata
              [3] -> Bengaluru
              [4] -> Chennai

Sample Output: The sorted names are:
               Agra
               Bengaluru
               Chennai
               Delhi
               Kolkata

Documentation
*/

void sort_names(char (*)[], int);    //sort_names function prototype                                   
void my_strcpy(char *str1, char *str2); //my_strcpy function prototype
int my_strcmp(char *str1, char *str2); //my_strcmp function prototype

int main()                                                          
{
    int n, i;
	printf("Enter the size : ");                                           
	scanf("%d", &n);

	char array[n][32]; //declaring character array

	printf("Enter the %d names of length max 32 characters in each\n", n);   
	for(i = 0; i < n; i++) //for loop to read elements
	{
	    printf("[%d] -> ", i);
	    scanf("%s", *(array + i));
	}
	sort_names(array, n);    //function call                                                 

	printf("\nThe sorted names are:\n");
	for(i = 0; i < n; i++) //for loop to print sorted elements
	{
	    printf("%s\n", *(array + i));
	}
    return 0;
}

void sort_names(char (*array)[32], int n)   //function defination                                
{
    int i, j;                                                               
    char temp[32];
    for (i = 0; i < n; i++) //for loop to compare the string and swap the string
    {
	for (j = i + 1; j < n; j++)
	{
	    if (my_strcmp(array[i], array[j]) > 0)                               
	    {
		my_strcpy(temp, array[i]);
		my_strcpy(array[i], array[j]);
		my_strcpy(array[j], temp);
	    }
	}
    }
}

void my_strcpy(char *str1, char *str2)  //function defination                                     
{
    char temp[32] = {'\0'};
    int i = 0;

    while (str2[i] != '\0') //while loop to copy the string
    {
	str1[i] = str2[i];
	i++;
    }
    str1[i] = '\0';
}

int my_strcmp(char *str1, char *str2)    // function defination
{
    while( (*str1 != '\0' && *str2 != '\0' ) && *str1 == *str2) //while loop to compare each character
    {
	str1++;
	str2++;
    }

    if(*str1 == *str2) //if condition to check the address of the both strings
    {
	return 0; 
    }

    else
    {
	return *str1 - *str2; //return the str1 address - str2 address
    }
}
