//https://leetcode.com/problems/3sum-closest/

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
// Learn how to do the 2 pointer more
// Learn what is qsort


int compare (const void * first, const void * second){
    int *a = (int *)first;
    int *b = (int *)second;

    if (*a > *b){
        return 1;
    } else if (*b > *a){
        return -1;
    }
    return 0;
}

int threeSumClosest(int* nums, int numsSize, int target){
    qsort (nums, numsSize, sizeof(int), compare);

    int closest = INT_MIN;
    int current = 0;
    int beginning;
    int ending;

    for (int i = 0; i < numsSize; i++){
        beginning = i + 1;
        ending = numsSize - 1;
        while (beginning != ending && beginning < numsSize && ending > i){
            printf ("i: %d ", nums[i]);
            printf ("beg: %d ", nums[beginning]);
            printf ("end: %d ", nums[ending]);
            
            current = nums[i] + nums[beginning] + nums[ending];
            printf ("curr: %d\n", current);
            if (abs (current - target) < abs (closest - target)){
                closest = current;
            }
            if (closest == target){
                return target;
            } else if (current < target){
                ++beginning;
            } else {
                --ending;
            }

            
        }
    }
    return closest;
}

int main(){
    int x[] = {1, 2, 4, 8, 16, 32, 64, 128, 256};
    printf ("%d\n", threeSumClosest(x, 9, 128));
    return 0;
}