#include <stdio.h>
#include <stdlib.h>
/*
Documentation
Name:Sunil M L
Date:01/04/2022
Description: Treat &x and &x + 1 as characters address.
             Both addresses difference will be sizeof x

sample execution: -
Test Case 1:
user@emertxe] ./sizeof
Size of int : 4 bytes
Size of char : 1 byte
Size of float : 4 bytes
Size of double : 8 bytes
Size of unsigned int : 4 bytes
Size of long int : 8 bytes        

Documentation
*/

#define SIZEOF(x) (char *)(&x + 1) - (char *)(&x) //macro defination
int main()
{
    int num1; //declaring int variable
    char ch1; //declaring char variable
    float num2; //declaring float variable
    double num3; //declaring double variable
    unsigned int num4; //declaring unsigned int variable
    long int num5; //declaring long int variable
    short int num6; //declaring short int variable
    unsigned char ch2; //declaring unsigned variable
    long long int num7; //declaring long long int variable
    long double num8; //declaring long double variable
    short unsigned int num9; //declaring short unsigned int variable
    long long unsigned int num10; //declaring long long unsigned int variable
    printf("Size of int : %ld\n", SIZEOF(num1)); //macro substitution and print the sizeof int
    printf("Size of char : %ld\n", SIZEOF(ch1)); //macro substitution and print the sizeof char
    printf("Size of float : %ld\n", SIZEOF(num2)); //macro substitution and print the sizeof float
    printf("Size of double : %ld\n", SIZEOF(num3)); //macro substitution and print the sizeof double
    printf("Size of unsigned int : %ld\n", SIZEOF(num4)); //macro substitution and print the sizeof unsigned int
    printf("Size of long int : %ld\n", SIZEOF(num5)); //macro substitution and print the sizeof long int
    printf("Size of short int : %ld\n", SIZEOF(num6)); //macro substitution and print the sizeof short int
    printf("Size of unsigned char : %ld\n", SIZEOF(ch2)); //macro substitution and print the sizeof unsigned char
    printf("Size of long long int : %ld\n", SIZEOF(num7)); //macro substitution and print the sizeof long long int
    printf("Size of long double : %ld\n", SIZEOF(num8)); //macro substitution and print the sizeof long double
    printf("Size of short unsigned int : %ld\n", SIZEOF(num9)); //macro substitution and print the sizeof short unsigned int
    printf("Size of long long unsigned int : %ld\n", SIZEOF(num10)); //macro substitution and print the sizeof long long unsigned int
    return 0;
}
