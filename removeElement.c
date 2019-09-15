// Problem : https://leetcode.com/problems/remove-element/
#include <stdlib.h>
#include <stdio.h>

void removes (int* nums, int numsSize, int val){
    for (int i = val; i < numsSize - 1; i ++){
        nums[i] = nums [i + 1];
    }
    nums [numsSize - 1] = '\0';
}

int removeElement(int* nums, int numsSize, int val){
    int len = 0;

    for (int i = 0; i < numsSize; i ++){
        if (nums [i] == val){
            if (i + 1 == numsSize){
                nums [i] = '\0';
            } else {
                removes (nums, numsSize, i);
            }
            i --;
            numsSize --;
        } else {
            len ++;
        }
    }
    return len;
}

int main (){
    int * i = malloc (10 * sizeof (int));
    i [0] = 1;
    i [1] = 1;
    i [2] = 3;
    i [3] = 5;
    i [4] = 4;
    i [5] = 1;
    i [6] = 1;
    int len = removeElement (i, 7, 1);
    for (int j = 0; j < len; j ++){
        printf ("%d ", i[j]);
    }
    return 0;
}