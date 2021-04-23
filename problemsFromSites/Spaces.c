#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

char *no_space(const char *str_in)
{

    char *result = malloc(sizeof(str_in));

    int j = 0;
    for (int i = 0; i < strlen(str_in); i++)
    {
        if (isspace(str_in[i]) == 0)
        {
            result[j] = str_in[i];
            j++;
        }
    }

    return result;
}

/* return an array of the string passed without blank spaces */