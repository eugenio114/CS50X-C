#include <stdio.h>
#include <cs50.h>

const int N = 3
float average(int array[]);

int main(void)
{
    int scores[N];

    //scores[0] = get_int("Score: ");
    //scores[1] = get_int("Score: ");
    //scores[2] = get_int("Score: ");

    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score: ");
    }

    printf("Average: %f\n", average(scores));
}

float average(int array[])
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += array[i];
    }
    return sum / (float) N;
}