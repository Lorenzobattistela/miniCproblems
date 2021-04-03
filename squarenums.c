#include <stdbool.h>
#include <math.h>

bool is_square(int n)
{

    float find = 0;
    int check = 0;
    if (n < 0)
    {
        return false;
    }

    find = sqrt(n);
    check = (int)find;

    if (find == check)
    {
        return true;
    }
    return 0;
}

/* find if the number is a perfect square or not */