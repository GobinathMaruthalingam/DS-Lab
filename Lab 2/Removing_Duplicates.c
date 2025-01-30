#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Generating random array
    for (i = 0; i < n; i++)
    {
        arr[i] = rand() % 10 + 1;
    }

    // Printing original array
    printf("Original array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // Removing duplicates
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n;)
        {
            if (arr[i] == arr[j])
            {
                // Shifting elements to left to remove duplicate
                for (k = j; k < n - 1; k++)
                {
                    arr[k] = arr[k + 1];
                }
                n--; // Reducing array size
            }
            else
            {
                j++;
            }
        }
    }

    // Printing array after removing duplicates
    printf("\nArray after removing duplicates: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
