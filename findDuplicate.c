//Problem: https://leetcode.com/problems/find-the-duplicate-number/

#include <stdio.h>
#include <stdlib.h>

int sort (const void *a, const void * b){
    int * x = (int *)a;
    int * y = (int *)b;

    return *x - *y;
}

int findDuplicate(int* nums, int numsSize){
    int arr[numsSize];
    for (int i = 0; i < numsSize; i ++){
        arr[i] = nums [i];
    }
    qsort (arr, numsSize, sizeof(int), sort);
    for (int i = 1; i < numsSize; i ++){
        printf ("%d ", arr[i]);
        if (arr[i] == arr[i-1]){
            return arr[i];
        }
    }
    return arr[0];
}

int main (){
    int arr [] = {2, 5, 9, 6, 9, 3, 8, 9, 7, 1};
    printf ("\n%d", findDuplicate(arr, 10)); 
}
