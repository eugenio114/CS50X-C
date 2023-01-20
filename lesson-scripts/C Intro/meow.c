#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int counter = 3;
    while (counter > 0)
    {
        printf("meow\n");
        counter--;
    }

    for (int i = 0; i < 3; i++)
    {
        printf("bau\n");
    }
}