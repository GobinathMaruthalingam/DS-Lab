#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    // Taking input for the length of the array
    printf("Enter length of array: ");
    scanf("%d", &n);

    int arr[n];

    // Generating & Printing random generated array
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10 + 1;
    }

    printf("Generated array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Counting  & Printing the frequency of each number
    int freq[10] = {0};

    for (int i = 0; i < n; i++)
    {
        freq[arr[i] - 1]++;
    }

    printf("Number frequencies:\n");
    for (int i = 0; i < 10; i++)
    {
        if (freq[i] > 0)
        {
            printf("%d: %d times\n", i + 1, freq[i]);
        }
    }

    return 0;
}
