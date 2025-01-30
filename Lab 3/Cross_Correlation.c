#include <stdio.h>
#include <stdlib.h>

void GenerateRandomMatrix(int matrix[][20], int size, int maxVal) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % maxVal + 1;  // Random values between 1 and maxVal
        }
    }
}

void printMatrix(int matrix[][20], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void applyKernel(int matrix[][20], int kernel[][20], int result[][20], int n, int k) {
    int offset = k / 2;  // Center of kernel

    for (int i = offset; i < n - offset; i++) {
        for (int j = offset; j < n - offset; j++) {
            int sum = 0;

            // Applying kernel
            for (int x = 0; x < k; x++) {
                for (int y = 0; y < k; y++) {
                    sum += matrix[i - offset + x][j - offset + y] * kernel[x][y];
                }
            }

            result[i][j] = sum / (k * k);
        }
    }
}

int main() {
    int n, k;
    
    printf("Enter the value of n (odd, max 20) - ");
    scanf("%d", &n);
    
    printf("Enter the value of k (odd, max 5) - ");
    scanf("%d", &k);

    if (n > 20 || k > 5 || n < 3 || k < 3 || n % 2 == 0 || k % 2 == 0) {
        printf("n and k must be odd and within valid limits.\n");
        return 1;
    }

    int matrix[20][20], kernel[20][20], result[20][20] = {0};

    // Generating & Printing matrix and kernel
    GenerateRandomMatrix(matrix, n, 5);
    GenerateRandomMatrix(kernel, k, 5);

    printf("\nOriginal Matrix:\n");
    printMatrix(matrix, n);

    printf("\nKernel Matrix:\n");
    printMatrix(kernel, k);

    // Applying kernel
    applyKernel(matrix, kernel, result, n, k);

    printf("\nFiltered Matrix:\n");
    printMatrix(result, n);

    return 0;
}