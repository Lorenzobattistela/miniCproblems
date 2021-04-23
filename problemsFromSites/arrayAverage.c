double find_average(double *array, int length)
{

    if (length == 0)
    {
        return 0;
    }

    double sum = 0;

    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }

    return sum / length;
}

/* Find the average of the elements in the array given */