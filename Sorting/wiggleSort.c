// Problem: https://leetcode.com/problems/wiggle-sort-ii/

#include <stdio.h>
#include <stdlib.h>


int sort (const void * first, const void * second){
    int a = *(int *)first;
    int b = *(int *)second;
    return a - b;
}

void wiggleSort(int* nums, int numsSize){
    if (numsSize == 1){
        return;
    }
    int arr[numsSize];
    qsort (nums, numsSize, sizeof (int), sort);

    int mid;
    if (numsSize % 2 == 0){
        mid = (numsSize / 2) - 1;
    } else {
        mid = (numsSize / 2);
    }
    int end = numsSize - 1;

    int i = 0;

    while (1){
        if (mid >= 0){
            arr[i] = nums[mid];
            i ++;
            mid--;
        }
        if (end >= numsSize / 2 && i < numsSize){
            arr[i] = nums[end];
            i ++;
            end --;
        }
        if (mid < 0 && end <= numsSize / 2){
            break;
        }
    }

    for (int i = 0; i < numsSize; i ++){
        nums[i] = arr[i];
    }
}

int main (){
    int arr [] = {1, 1, 1, 1, 2, 2, 2};
    int len = 7;
    wiggleSort (arr, len);
    for (int i = 0; i < len; i ++){
        printf ("%d ", arr[i]);
    }
    
}
