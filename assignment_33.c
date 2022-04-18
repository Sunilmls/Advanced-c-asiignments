#include<stdio.h>
/*
Documentation
Name:Sunil M L
Date:28/03/2022
Description: Read characters from user till EOF
             If EOF received, print the character count, word count, and line count.
             Code should exactly work like wc command.

Test Case 1:
user@emertxe] ./my_wc
Sample Input: Hello world
              Dennis Ritchie
              Linux
Sample Output: Character count : 33
               Line count : 3
               Word count : 5

Test Case 2:
Hello         world
Dennis    Ritchie
Linux
Character count : 39
Line count : 3
Word count : 5

Documentation
*/

int main()
{
    int chrtcnt = 0, wrdcnt = 0, lincnt = 0, i = 0;
    char ch, temp = '0';
    while((ch = getchar()) != EOF) 
    {
        if (ch != ' ' && ch != '\n')
        {
            chrtcnt++;
            if(temp == '0' )
            {
                wrdcnt++;
            }
            if(temp == ' ' || temp == '\n')
            {
                wrdcnt++;
            }
            temp = ch;
        }
        else if(ch == ' ')
        {
                chrtcnt++;
                temp = ch;
        }
       else if (ch == '\n')
        {
                chrtcnt++;
                lincnt++;
                temp = ch;
        }
    }
    printf("\n");
    printf("Character count : %d\n", chrtcnt);
    printf("Line count : %d\n", lincnt);
    printf("Word count : %d\n", wrdcnt);
}
