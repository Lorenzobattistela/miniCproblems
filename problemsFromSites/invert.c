/*Given a set of numbers, return the additive inverse of each. Each positive becomes negatives, and the negatives become positives. */

#include <stddef.h>

void invert(int *values, size_t values_size)
{
    for (int i = 0; i < values_size; i++)
    {
        if (values[i] > 0 || values[i] < 0)
        {
            values[i] = values[i] - (2 * values[i]);
        }

        else
        {
            values[i] = 0;
        }
    }
}