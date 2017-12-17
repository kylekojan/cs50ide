#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    //prompts user for name and stores it as variable
    printf("Enter your name: ");
    string s = get_string();
    if(s != NULL)
    {
        //initializes character count
         int count = 0;

        //iterate over each character
       for (int i = 0, n = strlen(s); i < n; i++)
       {
           //prints first character of each word, and ignores extra spaces

           if(s[i] != ' ' && count == 0)
           {
               printf("%c", toupper(s[i]));
               count++;
           }
           else if(s[i] != ' ' && count > 0)
           {
               count ++;
           }
           else
           {
               count = 0;
           }
       }
        printf("\n");
    }

}