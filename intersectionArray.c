// Problem: https://leetcode.com/problems/intersection-of-two-arrays-ii/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int * intersector (int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int * ans = malloc (nums1Size * sizeof (int));
    int counter = 0;
    bool check = false;

    for (int i = 0; i < nums2Size; i ++){
        if (counter == nums1Size){
            (*returnSize) = counter;
            return ans;
        } else if (check){
            if (nums1[counter] == nums2[i]){
                printf ("%d\n", i);
                ans[counter] = nums2[i];
                counter ++;
            } else{
                (*returnSize) = counter;
                return ans;
            }
        } else if (nums1[counter] == nums2[i]){
            printf ("%d\n", i);
            ans[counter] = nums1[i];
            check = true;
            counter ++;
        }
    }
    free (ans);
    *returnSize = 0;
    return NULL;

}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    if (nums1Size == 0 || nums2Size == 0){
        *returnSize = 0;
        return NULL;
    }
    if (nums1Size < nums2Size){
        return intersector (nums1, nums1Size, nums2, nums2Size, returnSize);
    } else{
        return intersector (nums2, nums2Size, nums1, nums1Size, returnSize);
    }
}

int main (){
    int arr [] = {4,9,5};
    int arr1 [] = {9,4,9,8,4};

    int size = 0;

    int * ans = intersect (arr, 3, arr1, 5, &size);

    for (int i = 0; i < size; i ++){
        printf ("%d ", ans[i]);
    }
    free (ans);

}