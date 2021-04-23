// Your task is to create a function that does four basic mathematical operations.
//The function should take three arguments - operation(string/char), value1(number), value2(number).
//The function should return result of numbers after applying the chosen operation.

int basic_op(char op, int value1, int value2)
{

    int result;

    if ((int)op == 43)
    {
        result = value1 + value2;
    }

    else if ((int)op == 45)
    {
        result = value1 - value2;
    }

    else if ((int)op == 42)
    {
        result = value1 * value2;
    }

    else if ((int)op == 47)
    {
        result = value1 / value2;
    }
    return result;
}