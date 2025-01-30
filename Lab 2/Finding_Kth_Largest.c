#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;

    printf("Enter length of array: ");
    scanf("%d", &n);

    printf("Enter K: ");
    scanf("%d", &k);

    int arr[n];

    // Generating a random array
    printf("Array is: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10 + 1; // Numbers between 1 and 10
        printf("%d ", arr[i]);
    }

    int min = arr[0];
    int max = arr[0];

    // Finding the minimum value in the array
    for (int i = 0; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    int temp;
    int track = min - 1;
    int count = 0;

    if (k <= n) {
        while (1) {
            max = arr[0];
            int maxIndex = 0;

            // Finding the maximum value
            for (int j = 0; j < n; j++) {
                if (arr[j] > max) {
                    max = arr[j];
                    maxIndex = j;
                }
            }

            // Track and update max element
            if (track == max) {
                count--;
            }

            track = max;
            arr[maxIndex] = min - 1;
            count++;

            if (count >= k) {
                break;
            }
        }

        // Final Output
        printf("\nKth largest value is: %d\n", max);
    } else {
        printf("\nInvalid Input for K\n");
    }

    return 0;
}