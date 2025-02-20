#include <stdio.h>

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        int minIdx = i;
        int maxIdx = i;

        for (int j = i + 1; j < n - i; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
            if (arr[j] > arr[maxIdx])
            {
                maxIdx = j;
            }
        }

        if (minIdx != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }

        if (maxIdx != n - i - 1)
        {
            int temp = arr[n - i - 1];
            arr[n - i - 1] = arr[maxIdx];
            arr[maxIdx] = temp;
        }
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal array:\n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("\nSorted array:\n");
    printArray(arr, n);

    return 0;
}