#include <stdio.h>
#include <stdlib.h>

void traverse(int arr[], int size)
{
    printf("Array elements: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void delete_at_beginning(int arr[], int *size)
{
    if (*size > 0)
    {
        for (int i = 0; i < *size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        (*size)--;
    }
    traverse(arr, *size);
}

void delete_at_end(int arr[], int *size)
{
    if (*size > 0)
    {
        (*size)--;
    }
    traverse(arr, *size);
}

void delete_at_index(int arr[], int *size, int index)
{
    if (index >= 0 && index < *size)
    {
        for (int i = index; i < *size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        (*size)--;
    }
    traverse(arr, *size);
}

void insert_at_beginning(int arr[], int *size, int value)
{
    for (int i = *size; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    (*size)++;
    traverse(arr, *size);
}

void insert_at_end(int arr[], int *size, int value)
{
    arr[*size] = value;
    (*size)++;
    traverse(arr, *size);
}

void insert_at_position(int arr[], int *size, int value, int index)
{
    if (index >= 0 && index <= *size)
    {
        for (int i = *size; i > index; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        (*size)++;
    }
    traverse(arr, *size);
}

void reverse_array(int arr[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
    traverse(arr, size);
}

void left_shift(int arr[], int size)
{
    if (size > 0)
    {
        int temp = arr[0];
        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[size - 1] = temp;
    }
    traverse(arr, size);
}

void right_shift(int arr[], int size)
{
    if (size > 0)
    {
        int temp = arr[size - 1];
        for (int i = size - 1; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = temp;
    }
    traverse(arr, size);
}

void normal_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    traverse(arr, size);
}

void sort_odd_positions(int arr[], int size)
{
    for (int i = 1; i < size - 1; i += 2)
    {
        for (int j = i + 2; j < size; j += 2)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    traverse(arr, size);
}

void sort_even_positions(int arr[], int size)
{
    for (int i = 0; i < size - 1; i += 2)
    {
        for (int j = i + 2; j < size; j += 2)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    traverse(arr, size);
}

void sort_even_elements(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] % 2 == 0 && arr[j] % 2 == 0 && arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    traverse(arr, size);
}

void sort_odd_elements(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] % 2 != 0 && arr[j] % 2 != 0 && arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    traverse(arr, size);
}

int main()
{
    int n;
    printf("Welcome to the Array Operations Program!\n");
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n + 10]; // Extra space for insertions
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    traverse(arr, n);
    delete_at_beginning(arr, &n);
    delete_at_end(arr, &n);
    delete_at_index(arr, &n, 1);
    insert_at_beginning(arr, &n, 99);
    insert_at_end(arr, &n, 88);
    insert_at_position(arr, &n, 77, 2);
    reverse_array(arr, n);
    left_shift(arr, n);
    right_shift(arr, n);
    normal_sort(arr, n);
    sort_odd_positions(arr, n);
    sort_even_positions(arr, n);
    sort_even_elements(arr, n);
    sort_odd_elements(arr, n);

    return 0;
}
