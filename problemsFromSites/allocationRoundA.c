/* --store number of houses

--store budget

--store prices on array [];

--organize from lower to higher

--store counter (increases when sum is correct)

--sum untill we run out of money

N - (x1 + x2);
*/

#include <stdio.h>

int sort(int prices[]);

int main(int argc, char *argv[])
{
    int test;
    printf("Test cases: ");
    scanf("%d", &test);

    int budget;
    printf("Budget: ");
    scanf("%d", &budget);

}

int sort(int prices[])
{
    for (int i = 0; i < sizeof(prices); i++)
    {
        if (prices[i] > prices[i + 1])
        {
            int tmp = prices[i + 1];
            prices[i + 1] = prices[i];
            prices[i] = tmp;
        }
    }
    return prices;
}
