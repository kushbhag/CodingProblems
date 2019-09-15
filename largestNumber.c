#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int sort (const void *c, const void *d){
    int x = *(int *)c;
    int y = *(int *)d;

    char a[15];
    char b[15];

    sprintf (a, "%d", x);
    sprintf (b, "%d", y);

    char ca[30];
    strcpy (ca, a);
    char da[30];
    strcpy (da, b);

    strcat (ca, b);
    strcat (da, a);

    for (int i = 0; i < 30; i ++){
        if (ca [i] > da[i]){
            return -1;
        } else if (ca[i] < da[i]){
            return 1;
        }
    }
    return 0;
}

char * largestNumber(int* nums, int numsSize){
    qsort (nums, numsSize, sizeof (int), sort);
    char * ans = malloc (1000 * sizeof (char));
    char x[10];

    if (nums[0] == 0){
        return "0";
    }

    sprintf (x, "%d", nums[0]);
    strcpy (ans, x);

    for (int i = 1; i < numsSize; i ++){
        sprintf (x, "%d", nums[i]);
        strcat (ans, x);
    }
    return ans;
}


int main (){
    int arr[] = {3, 30, 34, 5, 9};

    char * a = largestNumber(arr, 5);

    printf ("%s", a);
    free (a);

    return 0;
}