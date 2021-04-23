

int main(void)
{
    int i = 0;
    int number;
    int sum;
    do
    {
        printf("Number: ");
        scanf("%d", number);
        sum += number;
        i++;
    } while (i < 100);

    printf("%i", sum);
}