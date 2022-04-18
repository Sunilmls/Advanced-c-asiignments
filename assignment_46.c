#include <stdio.h>
#include <stdlib.h>
/*
Documentation
Name:Sunil M L
Date:05/04/2022
Description: Allocate 8 consecutive bytes in memory
             Provide a display menu
            1. Add element
            2. Remove element
            3. Display element
            4. Exit from the program
            It should allow to add elements of different data types which data type size is less than or equal to 8
           
Sample execution: -
Test Case 1:
user@emertxe] ./mem_manager
Menu :
1. Add element
2. Remove element
3. Display element
4. Exit from the program

Choice ---> 1
Enter the type you have to insert:
1. int
2. char
3. float
4. double
Choice ---> 2
Enter the char : k
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Choice ---> 3
-------------------------
0 -> k
-------------------------
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Choice ---> 1
Enter the type you have to insert:
1. int
2. char
3. float
4. double
Choice ---> 1
Enter the int : 10
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Choice ---> 3
------------------------
0 -> k (char)
1 -> 10 (int)
------------------------
1. Add element
2. Remove element
3. Display element
4. Exit from the program

Choice ---> 2
0 -> k
1 -> 10
Enter the index value to be deleted : 0
index 0 successfully deleted.
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Choice ---> 4

Documentation
*/

#define ROW 4 //define macro
#define COL 10000 //define macro

static int eCount = 0; //declaring static int variable

struct displayval //structure data type declaration
{
    char *addrs;
    char *dType;
};

void add_Element(char (*)[],  void *, void *, int); //function prototype
void remove_Element(char (* )[], void *, int ); //function prototype

int main()
{
    int choice1, choice2, count, count1; 
    struct displayval display[8]; //declaring structure data type variable
    char option;
    
    static void *vptr; //declaring ststic void pointer
    void *eptr; //declaring void pointer
    
    int num;
    char character;
    float fnum;
    double dnum;
    
    char * const ptr = (char *) malloc(8 * sizeof(char)); //dynamic memory allocation for constant pointer
    vptr = (char *)ptr; //void pointer typecasting to char
    eptr = (char *)(ptr + sizeof(vptr) - 1); //void pointer typecasting to char 
    
    do //do while loop for continious display
    {
        char type[ROW][COL] = { "int", "char", "float", "double" }; //char array for data type
        printf(" 1.Add element\n 2.Remove element\n 3.Display element\n 4.Exit from the program\n ");
        printf("Choice ---> ");
        scanf("%d", &choice1);
        
        switch (choice1) //switch case for print menu
        {
            case 1:
                printf(" Enter the type you have to insert:\n");
                printf(" 1.int\n 2.char\n 3.float\n 4.double\n");
                printf(" Choice ---> ");
                scanf("%d", &choice2);
                
                switch (choice2)  //switch case for select data types
                {
                    case 1: //adding integer number
                        printf("Enter the int : ");
                        scanf("%d", &num);
                        if ((eptr - vptr + 1) < 4) //if condition to check memory space avaliable
                        {
                            printf("Error: End of memeory. Cannot add int. \n" );
                            break;
                        }
                        display[eCount].addrs = vptr;
                        display[eCount].dType = *(type + choice2 - 1);
                        
                        add_Element((type + choice2 - 1), &num, vptr, sizeof(num)); //function call
                        
                        vptr = (void *)vptr + sizeof(*((int *) vptr));
                        
                        break;
                    case 2: //adding character
                        printf("Enter the char : ");
                        scanf(" %c", &character);
                        
                        if (((int *)eptr - (int *)vptr + 1) < 1) //if condition to check memory space avaliable
                        {
                            printf("Error: End of memeory. Cannot add char. \n" );
                            break;
                        }
                        
                        display[eCount].addrs = vptr;
                        display[eCount].dType = *(type + choice2 - 1);
                        
                        add_Element((type + choice2 - 1), &character, vptr, sizeof(character)); //function call
                        
                        vptr = (char *)vptr + sizeof(*((char *)vptr));
                        
                        break;
                        
                    case 3: //case for adding float number
                           printf("Enter the float : ");
                           scanf("%f", &fnum);
                        
                        if ((eptr - vptr + 1) < 4) //if condition to check memory space avaliable
                        {
                            printf("Error: End of memeory. Cannot add float. \n" );
                            break;
                        }
                        display[eCount].addrs = vptr;
                        display[eCount].dType = *(type + choice2 - 1);
        
                        add_Element((type + choice2 - 1), &fnum, vptr, sizeof(fnum)); //function call
                        
                        vptr = vptr + sizeof(*((float *)vptr));
                        
                        break;
                        
                    case 4: //case for adding double number
                        printf("Enter the double : ");
                        scanf("%lf", &dnum);
                        
                        if ((eptr - vptr + 1) < 8) //if condition to check memory space avaliable
                        {
                            printf("Error: End of memeory. Cannot add double. \n" );
                            break;
                        }
                        
                        display[eCount].addrs = vptr;
                        display[eCount].dType = *(type + choice2 - 1);
                        
                        add_Element((type + choice2 - 1), &dnum, vptr, sizeof(dnum)); //function call
                        
                        vptr = vptr + sizeof(*((double *)vptr));
                        
                        break;
                        
                    default:
                        printf("Invalid option\n");
                        break;
                }
                break;
                
            case 2: //case for removing elements
             for (count = 0; count < eCount ; count++)
                {
                    if (*(display[count].dType) == 'c') //if condition to display char
                    {
                         printf("%d -> %c (char) \n", count, (char) *(display[count].addrs));
                    }
                    if (*(display[count].dType) == 'i') //if condition to display int
                    {
                        printf("%d -> %d (int) \n", count, (int) *(display[count].addrs));
                    }
                    if (*(display[count].dType) == 'f') //if condition to display float
                    {
                        printf("%d -> %f (float) \n", count, *((float *)(display[count].addrs)));
                    }
                    if (*(display[count].dType) == 'd') //if condition to display double
                    {
                        printf("%d -> %lf (double) \n", count, *((double *)(display[count].addrs)));
                    }
                }
              printf("Enter the index value to be deleted: ");
                scanf("%d", &choice2);
                switch (choice2)  //switch case to remove numbers
                {
                    case 0: 
                        display[eCount - 1].addrs = vptr;
                        remove_Element((type + choice2 - 1), vptr, sizeof(int)); //function call
                        break;
                    case 1:  
                        display[eCount - 1].addrs = vptr;
                        remove_Element((type + choice2 - 1), vptr, sizeof(char)); //function call
                        break;
                        
                    case 2: 
                        display[eCount - 1].addrs = vptr;
                        remove_Element((type + choice2 - 1), vptr, sizeof(float)); //function call
                        break;
                        
                    case 3: 
                        display[eCount - 1].addrs = vptr;
                        remove_Element((type + choice2 - 1), vptr, sizeof(double)); //function call
                        break;
                    default:
                        printf("Invalid option\n");
                        break;
                }
                printf("index %d deleted\n", choice2);
                break;
            case 3: //case for display elements
                printf("To display %d values: \n", eCount);
                for (count = 0; count < eCount ; count++)
                {
                    if (*(display[count].dType) == 'c') //if condition to display char
                    {
                         printf("%d -> %c (char) \n", count, (char) *(display[count].addrs));
                    }
                    if (*(display[count].dType) == 'i') //if condition to display int
                    {
                        printf("%d -> %d (int) \n", count, (int) *(display[count].addrs));
                    }
                    if (*(display[count].dType) == 'f') //if condition to display float
                    {
                        printf("%d -> %f (float) \n", count, *((float *)(display[count].addrs)));
                    }
                    if (*(display[count].dType) == 'd') //if condition to display double
                    {
                        printf("%d -> %lf (double) \n", count, *((double *)(display[count].addrs)));
                    }
                }
                printf("\n");
                
            break;
            case 4:  //case for exit 
                   exit(0);
        }
        printf("Do you want to Continue(y/n): ");
        scanf("\n%s",&option);
        
    } while (option == 'y' || option == 'Y'); //while loop to continious display
    
    return 0;
}

void add_Element(char (* typeOfData)[], void *ptr, void *ptr2, int size) //function defination
{
    int i;
    char *a = ptr;
    char *b = ptr2;
    
    eCount++;
    for (i = 0; i < size; i++) //for loop for adding elements
    {
        b[i] = a[i];
    }
    
}
void remove_Element(char (* typeOfData)[], void *ptr, int size) //function defination
{
    int i;
    char *b = ptr;
    for (i = 0; i < size; i++) //for loop for remove elements
    {
        b[i] = '\0';
    }
    
}
