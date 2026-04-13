#include <stdlib.h>
#include <stdio.h>

int comp(const void *a,const void *b){

    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    return (arg1 > arg2) - (arg1 < arg2);
}

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    
for(int i = 0 ; i < numsSize ; i++){
    nums[i] *= nums[i];
}

qsort(nums,numsSize,sizeof(int),comp);
int* arr = malloc(numsSize * sizeof(int));
for(int i = 0 ; i < numsSize ; i++)arr[i] = nums[i];

*returnSize = numsSize;

return arr;

}

int main(){

int numsSize = 5;
int returnSize = 5;
int *ptr = &returnSize;
int nums[5] = {-4,-1,0,3,10};

for(int i = 0 ; i < numsSize ; i++){
    printf("%d ",nums[i]);
}
printf("\n\n");

int *arr = sortedSquares(nums,numsSize,ptr);


for(int i = 0 ; i < numsSize ; i++){
    printf("%d ",arr[i]);

}










}

