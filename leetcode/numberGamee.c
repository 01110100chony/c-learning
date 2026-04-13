#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    return (arg1 > arg2) - (arg1 < arg2);
}

int* numberGame(int* nums, int numsSize, int* returnSize) {
   
    qsort(nums, numsSize, sizeof(int), comp);

    int *arr = malloc(numsSize * sizeof(int));

    *returnSize = numsSize;

    for (int i = 0; i < numsSize; i += 2){
        arr[i] = nums[i + 1];  
        arr[i + 1] = nums[i];  
    }

    return arr; 
}