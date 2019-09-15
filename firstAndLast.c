//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/

// Understand what a binar search is

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int beg = numsSize / 2;
    int end = 0;
    int increment = beg;
    int * returnArray = malloc(2 * sizeof(int));
    *returnSize = 2;
    bool check = false;
    bool left = false;
    bool right = false;

    if (numsSize == 0){
        returnArray [0] = -1;
        returnArray [1] = -1;
        return returnArray;
    }
    while (1){
        printf ("%d\n", beg);
        if (check){
            if (end + 1 < numsSize && nums [end + 1] == target){
                end ++;
            } else {
                right = true;
                returnArray [1] = end;
            }
            if (beg > 0 && nums [beg - 1] == target){
                beg --;
            } else {
                left = true;
                returnArray [0] = beg;
            }

            if (left && right){
                return returnArray;
            }
        } else if (beg < 0 || beg >= numsSize || end > numsSize){
            printf ("%d\n", end);
            returnArray [0] = -1;
            returnArray [1] = -1;
            return returnArray;
        } else if (nums[beg] == target){
            end = beg;
            check = true;
        } else if (nums[beg] < target){
            if (increment / 2 == 0){
                beg ++;
            } else{
                increment /= 2;
                beg += increment;
            }
            end ++;
        } else {
            if (increment / 2 == 0){
                beg --;
            } else{
                increment / 2;
                beg -= increment;
            }
            end ++;
        } 
    }   
    return returnArray;
}

int main (){
    int nums [15] = {0, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 4, 4};
    int k = 0;
    int * returnSize = &k;
    int * final = searchRange (nums, 15, 3, returnSize);
    printf ("%d ", final [0]);
    printf ("%d\n", final [1]);
    printf ("%d", *returnSize);
    free (final);
}
