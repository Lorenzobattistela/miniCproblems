/*Check to see if a string has the same amount of 'x's and 'o's. The method must return a boolean and be case insensitive. The string can contain any char.*/

#include <stdbool.h>

bool xo(const char *str)
{
    int xcount = 0;
    int ocount = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == 'x' || str[i] == 'X')
        {
            xcount++;
        }

        else if (str[i] == 'o' || str[i] == 'O')
        {
            ocount++;
        }
    }

    if (xcount == ocount)
    {
        return true;
    }

    else
    {
        return false;
    }
}