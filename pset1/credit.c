#include <stdio.h>
#include <cs50.h>

int iterate(long long n);
int remaining(long long n);
int length(long long n);
int first_digits(long long n);

int main(void)
{
    printf("Enter Credit Card Number: ");
    //need to add some code to verify CC # is valid
    long long cc_number = get_long_long();
    int luhn = iterate(cc_number) + remaining(cc_number);
    int first = first_digits(cc_number);
    int len = length(cc_number);
    printf("luhn = %i and firstdigits = %i and length = %i\n", luhn, first, len); //this can be removed after program is complete
    if(luhn % 10 == 0 && len == 15 && (first == 34 || first == 37))
    {
        printf("AMEX\n");
    }
    else if(luhn % 10 == 0 && (len == 13 || len == 16) && (first > 39 && first < 50))
    {
        printf("VISA\n");
    }
    else if(luhn % 10 == 0 && len == 16 && (first > 50 && first < 56))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}

int iterate(long long n)
{
    int digit;
    int total = 0;
    int i = 0;
    while(n)
    {
        digit = n % 10;
        n /= 10;
        if (i % 2 == 1)
        {
            int db = digit * 2;
            int j = (db) % 10;
            if(db > 10)
            {
                int k = (db / 10) % 10;
                total = total + k;
            }
            total = total + j;
        }
        i++;

    }
    return total;
}

int remaining(long long n)
{
    int digit;
    int total = 0;
    int i = 0;
    while(n)
    {
        digit = n % 10;
        n /= 10;
        if (i % 2 == 0)
        {
            total = total + digit;
        }
        i++;

    }
    return total;
}

int length(long long n)
{
    int count = 0;
    while(n != 0)
    {
        n /= 10;
        ++count;
    }
    return count;
}

int first_digits(long long n)
{
    while(n >= 100)
    {
    n /= 10;

    }
    return n;
}
