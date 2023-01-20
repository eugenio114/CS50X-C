#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int starting_n, end_n;
    do
    {
        starting_n = get_int("Start Size: ");
    }
    while (starting_n < 9);

    // TODO: Prompt for end size
    do
    {
        end_n = get_int("End Size: ");
    }
    while (end_n < starting_n);

    // TODO: Calculate number of years until we reach threshold

    int y = 0;
    while (starting_n < end_n)
    {
        starting_n = starting_n + (starting_n / 3) - (starting_n / 4);
        y++;
    }

    // TODO: Print number of years
    printf("Years: %d\n", y);
}
