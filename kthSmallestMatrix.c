#include <stdio.h>

int sort (const void *first, const void *second){
    int *a = (int *)first;
    int *b = (int *)second;

    if (*a > *b){
        return 1;
    } else if (*a < *b){
        return -1;
    }
    return 0;
}

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k){
    int arr[matrixSize * matrixSize];
    int x = 0;

    for (int i = 0; i < matrixSize; i ++){
        for (int j = 0; j < matrixSize; j ++){
            arr[x] = (matrix[i])[j];
            x++;
        }
    }
    qsort (arr, matrixSize * matrixSize, sizeof (int), sort);
    return arr[k - 1];
}