#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *s = get_string("s: ");
    if (s == NULL)
    {
        retun 1;
    }


    char *t = malloc(strlen(s + 1));
    if (t == NULL)
    {
        return 1;
    }

    strcopy(t, s);

    //for (int i = 0, n = strlen(s) + 1; i < n; i++)
    //{
    //    t[i] = s[i];
    //}

    if (strlen(t) > 0)
    {
         t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    free(t);
}