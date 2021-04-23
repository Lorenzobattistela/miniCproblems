#include <stddef.h>
#include <stdlib.h>

// return a *new, dynamically allocated* array with each element doubled.
int *maps(const int *arr, size_t size)
{
    int *result = malloc(sizeof(arr));

    for (int i = 0; i < size; i++)
    {
        result[i] = 2 * (arr[i]);
    }

    return result;
}