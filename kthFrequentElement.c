// Problem: https://leetcode.com/problems/top-k-frequent-elements/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct hash{
    int num;
    int quant;
};

int sort (const void *first, const void *second){
    int * a = (int *)first;
    int * b = (int *)second;

    if (*a  > *b){
        return 1;
    } else if (*a < *b){
        return -1;
    }
    return 0;
}

int sortHash (const void *first, const void *second){
    struct hash * a = (struct hash *)first;
    struct hash * b = (struct hash *)second;

    if (a->quant  > b->quant){
        return -1;
    } else if (a->quant < b->quant){
        return 1;
    }
    return 0;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    qsort(nums, numsSize, sizeof(int), sort);

    assert (k > 0);

    *returnSize = k;

    struct hash ans[numsSize];
    int counter = 0;
    int len = 0;

    ans[0].num = nums[0];

    for (int i = 0; i < numsSize; i ++){
        if (nums[i] == ans[counter].num){
            len ++;
        } else{
            ans[counter].quant = len;
            counter ++;
            ans[counter].num = nums[i];
            len = 1;
        }
    }
    ans[counter].quant = len;

    
    counter ++;
    int *final = malloc (k * sizeof(int));
    qsort (ans, counter, sizeof (struct hash), sortHash);

    for (int i = 0; i < k; i ++){
        final[i] = ans[i].num;
    }
    return final;
}

int main (){
    int nums[] = {1, 1, 2, 4, 3, 3, 4};
    int size = 0;
    int * arr = topKFrequent (nums, 7, 2, &size);
    printf ("[");
    for (int i = 0; i < size; i++){
        printf ("%d ", arr [i]);
    }
    printf ("]");
    free (arr);
}