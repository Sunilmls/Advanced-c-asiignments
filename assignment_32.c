#include <stdio.h>
/*
Documentation
Name:Sunil M L
Date:16/03/2022
Description: Read n and n no.of elements from user and store them into an array.
             Run a loop for printing the elements in sorted order.

Test Case 1:
user@emertxe] ./sort
Sample Input : Enter the size : 5
               Enter 5 elements 
                10 1 3 8 -1
Sample Output: After sorting: -1 1 3 8 10
               Original array values 10 1 3 8 -1

Test Case 2:
user@emertxe] ./sort
Enter the size : 7
Enter 7 elements 
1 3 2 5 4 7 6
After sorting: 1 2 3 4 5 6 7
Original array values 1 3 2 5 4 7 6

Test Case 3:
user@emertxe] ./sort
Enter the size : 4
Enter 4 elements 
-1 -2  4 3
After sorting: -2 -1 3 4
Original array values -1 -2  4 3

Documentation
*/

void print_sort(int [], int); //function prototype
void print_sort(int arr[], int size) //function defination
{
    int i, j, smallest = arr[0], largest = arr[0], temp, temp1, n; //declaring variables
    for (i = 0; i < size; i++) //for loop to find smallest and largest number
    {
        if (arr[i] < smallest) //if condition to find smallest number
        {
            smallest = arr[i]; //if condition true intialize smallest with arr[i] 
        }
        if (arr[i] > largest) //if condition to find largest number
        {
            largest = arr[i]; //if condition true intialize arr[i] to largest
        }
    }
    temp1 = smallest; //intialize temp1 variable with smallest
    temp = largest; //intialize temp with largest
    for ( i = 1; i < size - 1; i++) //for loop for sort and store the elements
    {
        for ( j = 0; j < size; j++) //for loop for sort the elements
        {
            if (arr[j] > smallest && arr[j] < temp) //if condition to find the smallest numbers
            {
                temp = arr[j]; //intialize temp with arr[j] value
                n = j; //intializing j value to n value
            }
        }
        arr[n] = arr[i]; //intilize arr[i] value to the arr[n] 
        smallest = temp; //intilize temp value to the smallest
        arr[i] = temp; //intialize temp value to the arr[i]
        temp = largest; //reintialize largest to the temp 
    }
    arr[0] = temp1; //intialize temp1 value to the arr[0]
    arr[size - 1] = largest; //intialize largest value to the arr[size - 1]
    printf("After sorting ");
    for(i = 0; i < size; i++) //for loop to print the sorted elemets
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    int size, iter; //declaring variables
    
    printf("Enter the size of the array : ");
    scanf("%d", &size);
    
    int arr[size]; //declaring array
    int arr1[size]; //declaring array to store original array elements 
    printf("Enter the  elements\n");
    for (iter = 0; iter < size; iter++) //for loop to read the array elements
    {
        scanf("%d", &arr[iter]);
    }
     for(iter = 0; iter < size; iter++) //for loop to store original array elements
    {
        arr1[iter] = arr[iter];
    }
    print_sort(arr, size); //function call
    printf("\nOriginal array values ");
    for(iter = 0; iter < size; iter++) //for loop to print original array elements
    {
        printf("%d ", arr1[iter]);
    }
    return 0;
}
