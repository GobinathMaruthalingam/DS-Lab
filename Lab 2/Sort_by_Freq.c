#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 10

int compare(const void *a, const void *b)
{
    return *(int *)b - *(int *)a; // Sort in descending order
}

int main()
{
    int n, arr[100], freq[MAX_VALUE + 1] = {0};

    printf("Enter array size: ");
    scanf("%d", &n);

    printf("Generated array: ");
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % MAX_VALUE + 1;
        printf("%d ", arr[i]);
        freq[arr[i]]++;
    }
    printf("\n");

    int sortedArr[100], index = 0;
    for (int i = 1; i <= MAX_VALUE; i++)
        for (int j = 0; j < freq[i]; j++)
            sortedArr[index++] = i;

    qsort(sortedArr, index, sizeof(int), compare);

    printf("Sorted by frequency: ");
    for (int i = 0; i < index; i++)
        printf("%d ", sortedArr[i]);

    return 0;
}
