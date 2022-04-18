#include <stdio.h>
/*
Documentation
Name:Sunil M L
Date:28/03/2022
Description: Check the memory assigning order of variables for checking whether little endian or big endian machine
             Little Endian:
                           --------------
                           Say int i = 10; gets stored in memory at
                           1000
                           1001
                           1002
                           1003
                           where 1000 contains LSB of i and 1003 contains MSB of i
                            char *ptr = &i; the ptr will now contain 1000

             Big Endian:
                           -----------
                           Say int i = 10; gets stored in memory at
                           1000
                           1001
                           1002
                           1003
                           where 1000 contains MSB of i and 1003 contains LSB of i
                           char *ptr = &i; the ptr will now contain 1000

            Read 2 byte or 4 byte data according to given size(short or Int). Swap the bytes and convert the given data to Big Endian 

Test Case 1:
user@emertxe] ./endianness
Sample Input: Enter the size: 2
              Enter any number in Hexadecimal: ABCD
Sample Output: After conversion CDAB

Test Case 2:
Enter the size: 4
Enter any number in Hexadecimal: 12345678
After conversion 78563412

Documentation
*/

int main()
{
    int size, num; //declaring integer variables
    int i; //declaring i
    char temp, *ptr; //declaring character varaiable and character pointer
    printf("Enter the size: ");
    scanf("%d", &size);
    printf("Enter any number in Hexadecimal: ");
    scanf("%x", &num);
    ptr = (char *) &num; //intilizing ptr with num address with character typecasting
    for ( i = 0; i < size / 2; i++) //for loop to swap the data
    {
        temp = *(ptr + i); //initilize temp with ptr + i data
        *(ptr + i) = *(ptr + size - i - 1); //intilize ptr + i with ptr + size - 1 - i
        *(ptr + size - i - 1) = temp; //intilize ptr + size - 1 - i with temp
    }
    printf("After conversion %x\n", num); //print Big endian data
    return 0;
    
}
