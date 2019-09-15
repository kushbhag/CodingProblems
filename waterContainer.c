// https://leetcode.com/problems/container-with-most-water/solution/


/*
BRUTE FORCE
int min(int num1, int num2) 
{
    return (num1 > num2 ) ? num2 : num1;
}

int maxArea(int* height, int heightSize){
    int max = 0;
    int area = max;

    for (int i = 0; i < heightSize; i ++){
        for (int j = i; j < heightSize; j ++){
            area = (j - i) * (min (height [j], height[i]));
            if (area > max){
                max = area;
            }
        }
    }
    return max;
} 

int  main (){
    int test[9] = {1,8,6,2,5,4,8,3,7};
    printf ("%d\n", maxArea (test, 9));
    return 0;
}
*/ 

int maxArea(int* height, int heightSize){
    int max = 0;
    int area = max;
    int i = 0;
    int j = heightSize - 1;
    
    while(1){
        area = j - i;
        if (height [j] > height [i]){
            area *= height [i];
            i++;
        } else{
            area *= height [j];
            j--;
        }
        
        if (area > max){
            max = area;
        }
        
        if (j == i){
            return max;
        }
    }

}
