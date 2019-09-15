// Problem: https://leetcode.com/problems/two-sum/


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

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    qsort (nums, numsSize, sizeof(int), sort);
    int * returnArray = malloc (2 * sizeof(int));
    *returnSize = 2;
    int end = numsSize - 1;
    int beg = 0;

    while (1){
        if (nums [end] + nums [beg] > target){
            end --;
        } else if (nums [end] + nums [beg] < target){
            beg ++;
        } else {
            returnArray [0] = beg;
            returnArray [1] = end;
            return returnArray;
        }
    }
}

int main (){
    int nums [] = {7, 2, 15, 11};
    int size = 0;
    int *returnSize = &size;
    int * final = twoSum (nums, 4, 9, returnSize);
    printf ("%d ", final [0]);
    printf ("%d\n", final [1]);
    free (final);
}