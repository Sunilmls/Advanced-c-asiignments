#include <stdio.h>
#include<stdlib.h>
/*
Documentation
Name:Sunil M L
Date:28/03/2022
Description: In probability theory and statistics, variance measures how far a set of numbers is spread out. A variance of zero indicates that all the values are identical. Variance is always non-negative: a small variance indicates that the data points tend to be very close to the mean (expected value) and hence to each other, while a high variance indicates that the data points are very spread out around the mean and from each other.
              Example:
                     x(input)                    D = X - Mean              D2
                        9                         -11                      121
                        12                        -8                       64
                        15                        -5                       25
                        18                        -2                       4
                        20                         0                       0
                        22                         2                       4
                        23                         3                       9
                        24                         4                       16
                        26                         6                       36
                        31                         11                      121
                        Sum = 200                                          Sum = 400
            Mean = (sum of x) / size
            where : size = Number of items in the input
            Formula to calculate the variance:
                                              sigma = (sum of D2 ) / size

Test Case 1:
user@emertxe] ./variance
Sample Input : Enter the no.of elements : 10
                Enter the 10 elements:
                                      [0] -> 9
                                      [1] -> 12
                                      [2] -> 15
                                      [3] -> 18
                                      [4] -> 20
                                      [5] -> 22
                                      [6] -> 23
                                      [7] -> 24
                                      [8] -> 26
                                      [9] -> 31
sample Output: Variance is 40.000000

Documentation
*/

float variance(int *, int); //function prototype
float variance(int *arr, int n) //function defination
{
    int i, sum = 0, mean; //declaring integer variables
    float D, D2, variance = 0; //declaring float variables
    for( i = 0; i < n; i++) //for loop to find the sum of the all elements
    {
        sum += arr[i]; //store sum with the addition of sum with arr[i]
    }
    mean = sum / n; //findinig mean
    for( i = 0; i < n; i++) //for loop to find the variance
    {
        D = arr[i] - mean; //store D with subtraction of arr[i] with the mean
        D2 = D * D; //finding square value of D
        variance += D2; //store variance with the D2 with variance
    }
    variance = variance / n; //finding the variance
    return variance; //return variance 
}

int main()
{
    int n, i; //integer variable declariation
    float var; //float variable declaration
    printf("Enter the no.of elements : ");
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int)); //dynamic memory allocation
    printf("Enter the %d elements : ", n);
    for( i = 0; i < n; i++) //for loop to read the elements to array
    {
        scanf("%d", &arr[i]);
    }
    var = variance(arr, n); //function call
    printf("Variance is %f", var); //print variance value
    return 0;
}
