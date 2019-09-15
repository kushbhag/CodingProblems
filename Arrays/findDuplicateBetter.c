// Problem: https://leetcode.com/problems/find-the-duplicate-number/
#include <stdio.h>

int findDuplicate(int* nums, int numsSize){
    int beg = 0;
    int mid = numsSize / 2;
    if (nums[beg] == nums[mid]){
            return nums[beg];
    }
    for (int i = 0; i < numsSize; i++){
        beg = nums[beg];
        if (nums[beg] == nums[mid]){
            return nums[beg];
        }
        mid = nums[mid];
        if (nums[beg] == nums[mid]){
            return nums[beg];
        }
    }
    return beg;
}

int main (){
    int arr[] = {1, 3, 2, 1, 4};
    printf ("%d\n", findDuplicate(arr, 5));
}
