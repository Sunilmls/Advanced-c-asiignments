#include <stdio.h>
#include <stdlib.h>
/*
Documentation
Name:Sunil M L
Date:01/04/2022
Description: Implement fragments using array of pointers.
             Rows are static and columns are dynamic. Fixed no.of rows and columns will vary for each row.
             Example:
             Read no.of rows from user and allocate the memory statically for rows.
             Read no.of columns for each row and allocate the memory dynamically.
             Let us Assume, Row = 3.
             Row[0] = 4 columns, Row[1] = 3 columns and Row[2] = 5 columns.
             While allocating the memory for columns you have allocate for no.of columns + 1 dynamically.
             After that read the values from user and calculate the average for each row seperatly and store that average in that extra memory block which you added while allocating the memory.

Test case 1:
user@emertxe] ./fragmentsEnter
Sample Input: Enter no.of rows : 3
              Enter no of columns in row[0] : 4
              Enter no of columns in row[1] : 3
              Enter no of columns in row[2] : 5
              Enter 4 values for row[0] : 1 2 3 4
              Enter 3 values for row[1] : 2 5 9
              Enter 5 values for row[2] : 1 3 2 4 1
Sample Output:
Before sorting output is:

1.000000 2.000000 3.000000 4.000000 2.500000

2.000000 5.000000 9.000000 5.333333

1.000000 3.000000 2.000000 4.000000 1.000000 2.200000

After sorting output is:

1.000000 3.000000 2.000000 4.000000 1.000000 2.200000

1.000000 2.000000 3.000000 4.000000 2.500000

2.000000 5.000000 9.000000 5.333333

Documentation
*/

int fragments(int , int *); //function prototype
int fragments(int rows, int *array) //function defination
{
    int i, j, temp1; //declaring integer variables
    float *arr[rows], sum; //declaring float pointer array
    float *temp; //declaring float pointer array
    for (i = 0; i < rows; i++) //for loop for allocating dynamic memory for col
    {
        arr[i] = malloc(array[i] + 1 * sizeof(float*)); //dynamic memory allocation using calloc
        printf("Enter %d values for row[%d]: ", array[i], i);
        for (j = 0; j < array[i]; j++) //for loop to read the elements for col
        {
            scanf(" %f", &arr[i][j]);
        }
    }
    printf("Before Sorting output is:\n");
    for (i = 0; i < rows; i++) //for loop for row
    {
        sum = 0; //intilize sum with 0
        for (j = 0; j < array[i]; j++) //for loop for col 
        {
            printf("%f ", arr[i][j]);
            sum = sum + arr[i][j]; //store sum with addition of arr[i][j] 
        }
        printf("%f\n", arr[i][j] = (sum / j)); //print the average value
    }
    for (i = 0; i < rows - 1; i++) //for loop to sort the elements
    {
        for (j = 0; j < rows - i - 1; j++) //for loop for col to store the elements
        {
            if (arr[j][array[j]] > arr[j + 1][array[ j + 1]]) //if condition to check the larger value
            {
                temp = arr[j];  //intilize temp with arr[j]
                arr[j] = arr[j + 1]; //intilize arr[j] with arr[ j + 1]
                arr[j + 1] = temp; //intilize arr[ j + 1] with temp
                temp1 = array[j]; //intilize temp1 with array[j]
                array[j] = array[ j + 1]; //initilize array[j] with arr[ j + 1]
                array[ j + 1] = temp1; //intilize arr[ j + 1] with temp
            }
        }
    }
    printf("After Sorting output is:\n");
    for (i = 0; i < rows; i++) //for loop to print values after sorted
    {
        for (j = 0; j < array[i] + 1; j++) //for loop for col
        {
            printf("%f ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int rows, i, j; //declaring integer variable
    printf("Enter no of rows: ");
    scanf("%d", &rows);
    int array[rows]; //declaring inter array
    for (i = 0; i < rows; i++) //for loop to read the colums no
    {
        printf("Enter no of columns in row[%d]:", i);
        scanf("%d", &array[i] );
    }
    fragments(rows, array); //function call
    return 0;
}
