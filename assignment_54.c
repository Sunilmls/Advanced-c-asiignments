#include <stdio.h>
#include <stdlib.h>
/*
Documentation
Name:Sunil M L
Date:01/04/2022
Description: Implement swap concept with the help of macro
            The type of arguments to swap will be passed as t
            swap (int, x, y) where x and y are of types int.

Sample execution: -
Test Case 1:
user@emertxe] ./swap
Sample Input:
1. Int
2. char
3. short
4. float
5. double
6. string
Enter you choice : 1

Enter the num1 : 10
Enter the num2 : 20

Sample Output:
After Swapping :
num1 : 20
num2 : 10
Documentation
*/

#define SWAP(t, num1, num2) t temp = num1; num1 = num2; num2 = temp;  //macro defination
int main()
{
    int n; //declaring integer variable
    printf(" 1. Int\n 2. char\n 3. short\n 4. float\n 5. double\n 6. string\n"); //prit options
    printf("Enter you choice : ");
    scanf("%d", &n);
    switch(n) //switch case statement of n
    {
        case 1 : //case 1 condition
        {
            int num1, num2; //declaring integer variable
            printf("Enter the num1 : ");
            scanf("%d", &num1);
            printf("Enter the num2 : ");
            scanf("%d", &num2);
            SWAP(int, num1, num2); //macro substitution
            printf("After Swapping : ");
            printf("num1 : %d", num1);
            printf("num2 : %d", num2);
        }
        break;
     case 2 : //case 2 condition
        {
            char ch1, ch2; //declaring character variables
            printf("Enter the ch1 : ");
            scanf(" %c", &ch1);
            printf("Enter the ch2 : ");
            scanf(" %c", &ch2);
            SWAP(char, ch1, ch2); //macro substitution
            printf("After Swapping : \n");
            printf("ch1 : %c\n", ch1);
            printf("ch2 : %c\n", ch2);
        }
        break;
    case 3 : //case 3 condition
        {
            short num1, num2; //declaring short variables
            printf("Enter the num1 : ");
            scanf("%hd", &num1);
            printf("Enter the num2 : ");
            scanf("%hd", &num2);
            SWAP(short, num1, num2); //macro substitution
            printf("After Swapping : \n");
            printf("num1 : %hd\n", num1);
            printf("num2 : %hd\n", num2);
        }
        break;
    case 4 : //case 4 condition
        {
            float num1, num2; //float variable declaration
            printf("Enter the num1 : ");
            scanf("%f", &num1);
            printf("Enter the num2 : ");
            scanf("%f", &num2);
            SWAP(float, num1, num2); //macro substitution
            printf("After Swapping :\n");
            printf("num1 : %f\n", num1);
            printf("num2 : %f\n", num2);
        }
        break;
    case 5 :
        {
            double num1, num2; //double variable declaration
            printf("Enter the num1 : ");
            scanf("%lf", &num1);
            printf("Enter the num2 : ");
            scanf("%lf", &num2);
            SWAP(double, num1, num2); //macro substitution
            printf("After Swapping : \n");
            printf("num1 : %lf\n", num1);
            printf("num2 : %lf\n", num2);
        }
        break;
    case 6 :
        {
            char *str1 = malloc(20 * sizeof(char)); //intlizing dynamic memory for character pointer str1
            char *str2 = malloc(20 * sizeof(char)); //intlizing dynamic memory for character pointer str2
            printf("Enter the str1 : ");
            scanf("%s", str1);
            printf("Enter the str2 : ");
            scanf("%s", str2);
            SWAP(char *, str1, str2); //macro substitution
            printf("After Swapping : \n");
            printf("str1 : %s\n", str1);
            printf("str2 : %s\n", str2);
        }
        break;
    }
    return 0;
}
