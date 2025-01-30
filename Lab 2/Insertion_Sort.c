#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, temp, count = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Generating random array
    for (i = 0; i < n; i++)
    {
        arr[i] = rand() % 10 + 1;
    }

    // Printing original array
    printf("Array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // Insertion Sort
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j]; // Shift element right
            j--;
            count++;
        }
        arr[j + 1] = temp;
    }

    // Printing sorted array
    printf("\n\nSorted array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nNumber of swaps: %d", count);

    return 0;
}
