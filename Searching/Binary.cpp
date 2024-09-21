#include <stdio.h>

int Binary_search(int[], int, int);

int main()
{
    int k[10], i, n, x, found;

    printf("\n enter number of elements :");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\n enter number ");
        scanf("%d", &k[i]);
    }

    printf("\n enter value to search :");
    scanf("%d", &x);

    found = Binary_search(k, n, x);
    if (found == -1)
    {
        printf("\n unsuccessfull search...");
    }
    else
    {
        printf("\n successfull search.. %d is at index %d of array", x, found);
    }
    return 0;
}

int Binary_search(int k[], int n, int x)
{
    int low, high, middle;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        middle = (low + high) / 2;

        if (x < k[middle])
        {
            high = middle - 1;
        }
        else if (x > k[middle])
        {
            low = middle + 1;
        }
        else
        {
            return middle;
        }
    }
    return -1;
}