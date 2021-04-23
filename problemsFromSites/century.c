/* Given a year, return the century it is in. */

#include <string.h>

int centuryFromYear(int year)
{
    int prefix = year / 100;

    if (year % 2 != 0)
    {
        return prefix + 1;
    }

    else
    {
        return prefix;
    }
}
