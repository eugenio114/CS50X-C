#include <cs50.h>
#include <stdio.h>
#include <string.h>

void draw(int n);e

int main(void)
{
    int height = get_int("Height: ");
    draw(height);
}

void draw(int n)
{
    //this keeps calling the draw function up until it does not draw row 0 and then returns
    if (n <= 0)
    {
        return;
    }

    draw(n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");

}