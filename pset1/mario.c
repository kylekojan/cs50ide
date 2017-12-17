#include <stdio.h>
#include <cs50.h>
//test
void pyramid(int n);

int main(void)
{
    printf("Height: ");
    int height = get_int();
    if(height > 23 || height < 0)
    {
        printf("Retry: ");
    }
    else
    {
        pyramid(height);
    }
}

void pyramid(int n)
{
    for(int i = 0; i < n; i++)
        {
            int spaces = n - (i + 1);
            int hash = i + 1;
            for(int j = 0; j < spaces; j++)
            {
                printf(" ");
            }
            for(int j = 0; j < hash; j++)
            {
                printf("#");
            }
            printf("  ");
            for(int j = 0; j < hash; j++)
            {
                printf("#");
            }
            for(int j = 0; j < spaces; j++)
            {
                printf(" ");
            }
            printf("\n");
        };
}