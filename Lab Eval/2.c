#include <stdio.h>

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int leftSub[n1], rightSub[n2];

    for (int i = 0; i < n1; i++)
        leftSub[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightSub[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftSub[i] <= rightSub[j])
        {
            arr[k] = leftSub[i];
            i++;
        }
        else
        {
            arr[k] = rightSub[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = leftSub[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = rightSub[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int n)
{
    int size;
    for (size = 1; size < n; size *= 2)
    {
        for (int left = 0; left < n - 1; left += 2 * size)
        {
            int mid = (left + size - 1 < n) ? (left + size - 1) : (n - 1);
            int right = (left + 2 * size - 1 < n) ? (left + 2 * size - 1) : (n - 1);

            if (mid < right)
            {
                merge(arr, left, mid, right);
            }
        }
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    mergeSort(arr, n);

    printf("\nSorted array: \n");
    printArray(arr, n);

    return 0;
    
}