#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the value of n (odd) - ");
    scanf("%d", &n);

    // We are fixing the window size to 3x3
    int k = 3;

    if (k > n || k % 2 == 0)
    {
        printf("Invalid input: k must be smaller than n and odd.\n");
        return 1;
    }

    int arr[n][n];
    int final[n][n];

    // Randomly initialize the array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = rand() % 10 + 1; // Values between 1 and 10
        }
    }

    // Display the original array
    printf("\nOriginal Array:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Apply box filter (averaging filter)
    int offset = k / 2; // To handle the window size (3x3 filter has an offset of 1)

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            int count = 0;

            // Traverse the window of size 3x3 around (i, j)
            for (int x = i - offset; x <= i + offset; x++)
            {
                for (int y = j - offset; y <= j + offset; y++)
                {
                    // Ensure we stay within bounds of the array
                    if (x >= 0 && x < n && y >= 0 && y < n)
                    {
                        sum += arr[x][y];
                        count++;
                    }
                }
            }

            // Set the final value as the average of the window
            final[i][j] = sum / count;
        }
    }

    // Display the filtered array
    printf("\nFiltered Array (After Box Filter):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", final[i][j]);
        }
        printf("\n");
    }

    return 0;
}