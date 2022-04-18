#include <stdio.h>
#include <stdlib.h>
/*
Documentation
Name:Sunil M L
Date:31/03/2022
Description:  Read no.of rows and columns for 2 arrays from user and allocate the memory dynamically using malloc or calloc (Assume Matrix A and Matrix B).
              Read the Matrix A and B from user.
              Find the product for matrix A with matrix B amd store the result in Matrix R.
              Let say Name of the matrix is A and no. Of rows = columns = 3.
               Matrix A
                        1     
                        2     
                        3     
                        1     
                        2     
                        3    
                        1     
                        2     
                        3    

              Matrix B
                        1     
                        1     
                        1     
                        2     
                        2    
                        2     
                        3     
                        3     
                        3     

                Final Result :
                              Result = A * B
                                       1     2      3                             1         1      1
                             R=     1     2      3                 x          2         2       2
                                       1     2      3                             3         3      3
                             R1 = [(1 * 1) + (2 * 2) + (3 * 3)  (1 * 1) + (2 * 2) + (3 * 3)   (1 * 1) + (2* 2) + (3 * 3)]
                Result matrix is
                                 14     
                                 14    
                                 14    
                                 14   
                                 14    
                                 14    
                                 14    
                                 14    
                                 14   

Test case1:
user@emertxe] ./transpose_product
Sample input: Enter number of rows : 3
              Enter number of columns : 3
              Enter values for 3 x 3 matrix :
                                             1      2      3
                                             1      2      3
                                             1      2      3
              Enter number of rows : 3
              Enter number of columns : 3
              Enter values for 3 x 3 matrix :
                                             1      1     1
                                             2      2     2
                                             3      3     3
Sample Output: Product of two matrix :
                                      14      14      14
                                      14      14      14
                                      14      14      14
                                      
Test case 2:
user@emertxe] ./transpose_product
Enter number of rows : 3
Enter number of columns : 3
Enter values for 3 x 3 matrix :
1      2      3
1      2      3
1      2      3
Enter number of rows : 2
Enter number of columns : 3
Matrix multiplication is not possible
Documentation
*/


int matrix_mul(int **, int, int, int **, int, int, int **, int, int); //functiom prototype
int matrix_mul(int **mat_a, int row1, int col1, int **mat_b, int row2, int col2, int **result, int row3, int col3) //function defination
 {
     int i, j, k; //variable declaration
     for (i = 0 ; i < row1; i++) //for loop for row1
        {
        for (j = 0 ; j < col2; j++) //for loop for col2
        {
            for(k = 0; k < row2; k++) //for loop store the product
            {
            result[i][j] = result[i][j] + mat_a[i][k] * mat_b[k][j]; //store the product in result matrix
            }
        }
        }
     printf("Product of two matrix : ");
     for (i = 0; i < row3; i++) //for loop to print the product matrix
        {
        for (j = 0; j < col3 ; j++) //for loop to print the product matrix
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
        }
 }

int main()
{
    int **mat_a, **mat_b, **result; //integer matrix declration
    int row1, row2, col1, col2, i, j; //integer variables declaration
    printf("Enter number of rows :");
    scanf("%d", &row1);  
    printf("Enter number of columns :");
    scanf("%d", &col1);  
    mat_a = calloc(row1, sizeof(int *)); //dynamic row memory allocation for mat_a
    for(i = 0; i < col1; i++) //for loop for dynamic column memory allocation
    {
        mat_a[i] = calloc(col1, sizeof(int)); //dynamic col memory allocation for mat_a
    }
    printf("Enter values for %d x %d matrix : ", row1, col1);
    for(i = 0; i < row1; i++) //for loop to read the elements for mat_a
    {
        for(j = 0; j < col1; j++) //for loop for read the col elements for mat_a
        {
            scanf("%d", &mat_a[i][j]);
        }
    }
    printf("Enter number of rows :");
    scanf("%d", &row2);  
    printf("Enter number of columns :");
    scanf("%d", &col2); 
    mat_b = calloc(row2, sizeof(int *));  //dynamic row memory allocation for mat_b
    for(i = 0; i <= col2; i++) //for loop for dynamic column memory allocation
    {
        mat_b[i] = calloc(col2, sizeof(int)); //dynamic col memory allocation for mat_b
    }
    if( row1 == col2) //if condition to check the matrix for multiplication
    {
    printf("Enter values for %d x %d matrix : ", row2, col2);
    for(i = 0; i < row2; i++) //for loop to read the elements for mat_b
    {
        for(j = 0; j < col2; j++) //for loop to read the col elements for mat_b
        {
            scanf("%d", &mat_b[i][j]);
        }
    }
    result = calloc(row1, sizeof(int *)); //dynamic row memory allocation for result
    for(i = 0; i < col2; i++)
    {
        result[i] = calloc(col2, sizeof(int)); //dynamic col memory allocation for result
    }
    matrix_mul(mat_a, row1, col1, mat_b, row2, col2, result, row1, col2); //function call
    }
    else //if condition false print error massage
    {
        printf("Matrix multiplication is not possible");
    }
    return 0;
}
    
