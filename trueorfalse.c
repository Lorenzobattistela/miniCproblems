/* Implement a function which convert the given boolean value into its string representation.

Note: Only valid inputs will be given. */

#include <stdbool.h>

//The returned string should be statically allocated and it won't be freed
const char *boolean_to_string(bool b)
{

    if ((int)b == 1)
    {
        return "true";
    }

    else if ((int)b == 0)
    {
        return "false";
    }

    else
    {
        return 0;
    }
}