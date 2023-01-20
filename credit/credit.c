#include <cs50.h>
#include <stdio.h>
#include <string.h>

//including functions build in code below
void brand_name(long long n);
void int_lenght(long long n);
int luhn_algorithm(long long n);

int main(void)
{
    // prompt for number of credit card
    long long n;
    do
    {
        n = get_long_long("Number: ");
    }
    while (n <= 0);

    // establishing validity of credit card using bran_name and luhn_algorithm functions
    if (luhn_algorithm(n) == 0)
    {
        printf("INVALID\n");
    }
    else
    {
        brand_name(n);
    }
}

// function to get number of digit in credit card number
void int_lenght(long long n)
{
    int nn = 0;
    while (n != 0)
    {
        n = n / 10;
        nn++;
    }
}

// function to check for the credit card number validity based on the luhn algorithm
int luhn_algorithm(long long n)
{
    int n1 = 0;
    int n2 = 0;
    long x = n;
    int total = 0;
    int m1;
    int m2;
    int d1;
    int d2;

    do
    {
        //sum last digit and remove it
        m1 = x % 10;
        x = x / 10;
        n1 = n1 + m1;

        //remove second last digit
        m2 = x % 10;
        x = x / 10;

        //multiply second last digit by 2 and add digits to n2

        m2 = m2 * 2;
        d1 = m2 % 10;
        d2 = m2 / 10;
        n2 = n2 + d1 + d2;
    }
    while (x > 0);
    total = n1 + n2;

    //this if statement check if the last value after the sums is 0
    if (total % 10 != 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//function to validate lenght and starting digits according to card brands
void brand_name(long long n)
{
    if ((n >= 34e13 && n < 35e13) || (n >= 37e13 && n < 38e13))
    {
        printf("AMEX\n");
    }
    else if ((n >= 51e14 && n < 56e14))
    {
        printf("MASTERCARD\n");
    }
    else if ((n >= 4e12 && n < 5e12) || (n >= 4e15 && n < 5e15))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}