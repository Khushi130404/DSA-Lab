#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int first, int second, int third, int size)
{
    int* temp = (int*)malloc(size * sizeof(int));
    if (temp == NULL) {
        printf("Memory allocation failed");
        exit(1);
    }
    int i = first, j = second, k = 0;

    while (i < second && j <= third)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
   if (i == second)
   {
        while (j <= third)
        {
            temp[k] = arr[j];
            k++;
            j++;
        }
    }
    else
    {
        while (i < second)
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
    }
    for (int l = 0; l < size; l++)
    {
        arr[first+l] = temp[l];
    }
    free(temp);
}

void split(int arr[], int start, int finish, int size)
{
    if (finish > start)
    {
        int middle = start + (finish - start) / 2;
        split(arr, start, middle, size);
        split(arr, middle + 1, finish, size);
        merge(arr, start, middle+1, finish, size);
    }
}

int main()
{
    int size;
    printf("\nEnter the size of array: ");
    scanf("%d", &size);
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed");
        return 1;
    }
    int exch = 0;
    printf("\nEnter the elements of array...\n");
    for (int i = 0; i < size; i++)
    {
        printf("arr[%d] = ", i + 1);
        scanf("%d", &arr[i]);
    }

    split(arr, 0, size - 1, size);

    printf("\n\nSorted array...");
    for (int i = 0; i < size; i++)
    {
        printf("\narr[%d] = %d", i + 1, arr[i]);
    }
    free(arr);
    return 0;
}
