// Problem: https://leetcode.com/problems/4sum-ii/

#include <stdio.h>

#include <stdlib.h>
#include <stdbool.h>

int sort (const void *a, const void *b){
    int * x = (int *)a;
    int * y = (int *)b;

    return *x - *y;
}

int fourSumCount(int* A, int ASize, int* B, int BSize, int* C, int CSize, int* D, int DSize){
    if (ASize == 0){
        return 0;
    }
    qsort (A, ASize, sizeof(int), sort);
    qsort (B, BSize, sizeof(int), sort);
    qsort (C, CSize, sizeof(int), sort);
    qsort (D, DSize, sizeof(int), sort);

    int total = 0;

    int placeholder = 0;
    bool back = false;

    int end = DSize - 1;
    int beg = 0;

    for (int i = 0; i < ASize; i++){
        for (int j = 0; j < BSize;){
            int sum = A[i] + B[j] + C[beg] + D[end];
            printf ("i = %d | j = %d | beg = %d | end = %d | SUM: %d\n", i, j, beg, end, sum);
            if (sum == 0){
                total ++;
            }

            if (end == 0  && back){
                beg = placeholder;
                end = DSize - 1;
                back = false;
                printf ("BARISTA");
            } else if (end <= 0 && beg >= DSize - 1){
                j ++;
                beg = 0;
                end = DSize - 1;
            } else if (sum < 0){
                if (beg == DSize - 1){
                    j ++;
                    beg = 0;
                    end = DSize - 1;
                } else {
                    beg ++;
                }
            } else if (sum > 0){
                if (end == 0){
                    j ++;
                    beg = 0;
                    end = DSize - 1;
                } else{
                    end --;
                }
            } else if (sum == 0){
                if (end == 0 && beg == DSize - 1){
                    j ++;
                    beg = 0;
                    end = DSize - 1;
                } else if (end == 0){
                    beg ++;
                } else if (beg == DSize - 1){
                    end --;
                } else {
                    end --;
                    placeholder = beg + 1;
                    back = true;
                }
            }
        }
    }

    return total;
}

int main (){
    int A[] = {-1,-1,1,1,1};
    int B[] = {-1,-1,0,0,1};
    int C[] = {-1,-1,-1,-1,1};
    int D[] = {-1,-1,0,0,1};

    int size = 5;

    printf ("\n%d\n", fourSumCount(A, size, B, size, C, size, D, size));
}