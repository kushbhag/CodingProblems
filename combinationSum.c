// Problem: https://leetcode.com/problems/combination-sum/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
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

void backtrack (int **columns, int *candidates, int candidatesSize, int* temp, int remain, int **returnColumnSizes, int start){
    if (remain < 0) {
        return;
    } else if (remain == 0){
        
    }

    for (int i = start; i < candidatesSize, i++){
        temp[x] = candidates[i];
        backtrack (columns, candidates, candidatesSize, temp, remain - candidates[i], returnColumnSizes, start);

    }
}

int** combinationSum(int* candidates, int candidatesSize, 
                    int target, int* returnSize, int** returnColumnSizes){
    int **columns = malloc (*returnSize * sizeof (int *));
    int *temp = malloc (sizeof (int));
    qsort(candidates, candidatesSize, sizeof(int), sort);
    backtrack (columns, candidates, candidatesSize, temp, target, returnColumnSizes, 0);
    return columns;
}

int main (){
    int candidates [5] = {5, 2, 3, 7, 10};
    int candidatesSize = 5;
    qsort(candidates, candidatesSize, sizeof(int), sort);
    for (int i = 0; i < candidatesSize; i++){
        printf ("%d ", candidates[i]);
    }
    return 0;
}