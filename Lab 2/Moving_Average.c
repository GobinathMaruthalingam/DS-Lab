#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;

    // Taking input for length of the array and the frequency
    printf("Enter length of array: ");
    scanf("%d", &n);
    
    printf("Enter the frequency): ");
    scanf("%d", &k);

    if (k <= 0 || k > n) {
        printf("Invalid window size!\n");
        return 1;
    }

    int arr[n];

    // Generating and printing random array
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10 + 1;
    }

    printf("Generated array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Calculating and printing the moving average
    printf("Moving averages: \n");

    // For first window (smaller than 'k')
    for (int j = 1; j < k; j++) {
        float sum = 0;
        for (int i = 0; i < j; i++) {
            sum += arr[i];
        }
        printf("%.2f ", sum / j);
    }

    // For the rest of the windows
    for (int j = 0; j < n - k + 1; j++) {
        float sum = 0;
        for (int i = j; i < k + j; i++) {
            sum += arr[i];
        }
        printf("%.2f ", sum / k);
    }
    printf("\n");

    return 0;
}