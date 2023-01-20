#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //asking for height input
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    //for loop to define row height
    for (int i = 0; i < n; i++)
    {
        // for loop to define number of spaces to print
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        // for loop to define number of hashes to print
        for (int z = 0; z <= i; z++)
        {
            printf("#");
        }
        printf("\n");
    }
}