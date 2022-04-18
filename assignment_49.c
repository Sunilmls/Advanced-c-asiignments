#include <stdio.h>
#include <stdlib.h>
/*
Documentation
Name:Sunil M L
Date:30/03/2022
Description: In recreational mathematics, a magic square is an arrangement of distinct numbers (i.e. each number is used once), usually integers, in a square grid, where the numbers in each row, and in each column, and the numbers in the main and secondary diagonals, all add up to the same number
             A magic square has the same number of rows as it has columns, and in conventional math notation, "n" stands for the number of rows (and columns) it has. Thus, a magic square always contains n2 numbers, and its size (the number of rows [and columns] it has) is described as being "of order n".
             Example: if n = 3, the magic square
                                               8      1      6
                                               3      5      7
                                               4      9      2
              
              Read an odd number n from user.
              Do error checking.
              Check the number is odd or not.
              If not, continue step a.
              Create an n X n matrix.
              Insert 1 to (n * n) numbers into matrix.
              Arrange the numbers in such a way that, adding the numbers in any direction, either row wise column wise or diagonal wise, should result in same answer.
              Allocate the memory dynamically using calloc.

Test Case 1:
user@emertxe] ./magic_square
Sample Input: Enter a number: 3
Sample Output: 
               8      1      6
               3      5      7
               4      9      2

Test Case 2:
Enter a number: 6
Error : Please enter only positive values
Documentation
*/

void magic_square(int **, int); //function prototype
void magic_square(int **arr, int n) //function defination
{
    int i, j, k; //variable declaration
    i = 0; //intilize i with 0
    j = n / 2; //intilize j with n / 2
    arr[i][j] = 1; //intilize arr[0][1] with 1
    for(k = 1; k < n * n; k++) //for loop to genarate n *n matrix
    {
        if(k % n == 0) //checking k value
        {
            i = i + 1; //replace i with i + 1
        }
        else //else condition
        {
            if( i == 0) //check i value is 0 or not 
            {
             i = n - 1;  //replace i with n - 1
            }
            else //else condition
            {
                i = i - 1; //replace i with i - 1
            }
            if(j == n - 1) //check j value is n - 1 or not
            {
                j = 0; //replace j with 0
            }
            else //else condition
            {
                j = j + 1; //replace j with j + 1
            }
        }
        arr[i][j] = k + 1; //initlize arr[i][j] with k + 1
    }
    
    for(i = 0; i < n; i++)  //for loop to print n * n matrix
    {
        for(j = 0; j < n; j++) // for loop to print n * n matrix
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int **arr; //declaring double pointer array
    int n, i; //intilize variables
    printf("Enter a number: ");
    scanf("%d", &n);
    if( n % 2 != 0) //if condition to check odd number
    {
        arr = calloc(n, sizeof(int *)); //dynamic memory allocation for row
        for(i = 0; i < n; i++)
        {
            arr[i] = calloc(n, sizeof(int)); //dynamic memory allocation for column
        }
        magic_square(arr, n); //function call
    }
    else //else condition to print error massages
    {
        printf("Error : Please enter only positive odd numbers");
    }
    return 0;
}
