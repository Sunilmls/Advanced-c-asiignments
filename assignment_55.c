#include <stdio.h>
#include <stdlib.h>
/*
Documentation
Name:Sunil M L
Date:02/04/2022
Description:  Implement an student record which will contain roll no., Name of student, subject marks, average and grade.
              Read number of students and declare array of structure with no.of students, then read number of subjects and n subject names.
              Read the particulars for each student.
              Roll.no
              Name.
              Score of each subject
              Calculate the average. Based on that decide the grade.       

Sample execution:
Test Case 1:
user@emertxe] ./student_record
Enter no.of students : 2
Enter no.of subjects : 2
Enter the name of subject 1 : Maths
Enter the name of subject 2 : Science
----------Enter the student datails-------------
Enter the student Roll no. : 1
Enter the student 1 name : Nandhu
Enter Maths mark : 99
Enter Science mark : 91
----------Enter the student datails-------------
Enter the student Roll no. : 2
Enter the student 2 name : Bindhu
Enter Maths mark : 88
Enter Science mark : 78
----Display Menu----
1. All student details
2. Particular student details
Enter your choice : 2

----Menu for Particular student----
1. Name.
2. Roll no.
Enter you choice : 1
Enter the name of the student : Nandhu
Roll No.   Name           Maths         Science       Average       Grade
1              Nandhu        99               91                95                  A
Do you want to continue to display(Y/y) : n
Documentation
*/

struct student //structure data type declaration
{
    char name[50]; //declaring character array for name
    int rollno; //declaring int variable for rollno
    char subject[50]; //declaring character array for subject
    int marks[100]; //declaring int variable for marks
    char grade; //declaring char variable for grade
};
int main()
{
    struct student stud[10]; //struture variable declaration
    int n1, n2, i, j, choice, avg = 0, num, k = 0, flag; //declaring integer variable
    char str[20], ch; //declaring character variables
    printf("Enter no of students: ");
    scanf("%d", &n1);
    printf("Enter no of subjects: ");
    scanf("%d", &n2);
    for(i = 1; i <= n1; i++) //for loop to read the subject names
    {
        printf("Enter the name of the subject%d: ", i);
        scanf("%s", stud[i].subject);
    }
    for(i = 1; i <= n1; i++ ) //for loop read the student info
    {
        printf("----Enter the student details----\n");
        printf("Enter the student%d Roll no: ", i);
        scanf("%d", &stud[i].rollno);
        printf("Enter the student%d name: ", i);
        scanf(" %s", stud[i].name);
        for(j = 1; j <= n2; j++) //for loop to read the subject marks
        {
            printf("Enter %s marks: ", stud[j].subject);
            scanf("%d", &stud[i].marks[j]);
        }
    }
        for(i = 1; i <= n1; i++) //for loop to find average
        {
            for(j = 1; j <= n2; j++) //for loop to find average
            {
                avg = avg + stud[i].marks[i]; //storing total marks
            }
            avg = avg / n2; //finding average
            if(avg >= 90) //if condition for A grade
            {
                stud[i].grade = 'A';
            }
            else if(avg >= 80 && avg < 90 ) //else if condition for b grade
            {
                stud[i].grade = 'B';
            }
            else if(avg >= 70 && avg < 80) //else if condition for c grade
            {
                stud[i].grade = 'C';
            }
            else if(avg >= 60 && avg < 50) //else if condition for d grade
            {
                stud[i].grade = 'D';
            }
            else if(avg >= 50 && avg < 40) //else if condition for e grade
            {
                stud[i].grade = 'E';
            }
            else //else condition for f grade
            {
                stud[i].grade = 'F';
            }
        }
        do //do while loop to print continious menu
        {
            printf("----Display Menu----\n");
            printf(" 1.All student details\n 2.Particular student details\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            if(choice == 1) //if condition to print all student details
            {
                printf("Rollno   Name     ");
                for(i = 1; i <= n2; i++) //for loop to print subject names
                {
                    printf("%-9s", stud[i].subject);
                }
                printf("grade\n");
                for(i = 1; i <= n1; i++) //for loop to print roll no
                {
                printf("%-9d", stud[i].rollno);
                printf("%-9s", stud[i].name);
                for(j = 1; j <= n2; j++)  //for loop to print subject marks
                {
                    printf("%-9d", stud[i].marks[j]);
                }
                 printf("%-9c\n", stud[i].grade);
                }
            }
            else if(choice == 2) //else condition for Particular student details
            {
                printf("----Menu for particular student----\n");
                printf(" 1.Name\n 2.Roll no\n");
                printf("Enter your choice: ");
                scanf(" %d", &choice);
                if (choice == 1) //if condition to print details based on name
                {
                  printf("Enter the name of the student: ");
                  scanf(" %s", str);
                for(i = 1; i <= n1; i++) //for loop to print student details
                {
                    k = 0;
                  while(str[k] != '\0' && stud[i].name[k] != '\0') //while loop to compare the string
                  {
                      if(str[k] != stud[i].name[k]) //if condition to check the character
                      {
                          flag = 1; //if string not eqaul set flag as 1
                          break; //exit from the loop
                      }
                      k++; //increase k value by 1
                  }
                if (flag != 1) //if condition to check name
                {
                 printf("Rollno   Name     ");
                for(k = 1; k <= n2; k++) //for loop to print subject
                {
                    printf("%-9s", stud[k].subject);
                }
                printf("grade\n");
                printf("%-9d", stud[i].rollno);
                printf("%-9s", stud[i].name);
                for(j = 1; j <= n2; j++) //for loop to print subject marks
                {
                    printf("%-9d", stud[i].marks[j]);
                }
                 printf("%-9c", stud[i].grade);
                }
                }
                }
                 if (choice == 2) //if condition to print details based on roll no
                {
                 printf("Enter the roll no: ");
                 scanf("%d", &num );
                for(i = 0; i <= n1; i++) //for loop to print student details
                {
                if (num == stud[i].rollno) //if condition to check roll no
                {
                 printf("Rollno   Name     ");
                for(k = 1; k <= n2; k++) //for loop to print subject names
                {
                    printf("%-9s", stud[k].subject);
                }
                printf("grade\n");
                printf("%-9d", stud[i].rollno);
                printf("%-9s", stud[i].name);
                for(j = 1; j <= n2; j++) //for loop to print subject marks
                {
                    printf("%-9d", stud[i].marks[j]);
                }
                 printf("%-9c", stud[i].grade);
                }
                }
                }
            }
            printf("\nDo you want to continue press to display(Y/y): ");
            scanf(" %c", &ch);
        }while(ch == 'y' || ch == 'Y'); //y to continue
        return 0;
    }
