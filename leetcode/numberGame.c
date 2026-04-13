#include <stdio.h>
#include <stdlib.h>
#define SIZE 6  
void swap(int* arr,int numsSize){
for(int i = 0 ; i < numsSize ; i+=2){
    int temp = arr[i];
    arr[i] = arr[i+1];
    arr[i + 1] = temp;
 }
}

int* numberGame(int* nums, int numsSize, int* returnSize) {
    
    int *arr = malloc(numsSize * sizeof(int));
       
     for(int i = 0 ; i < numsSize ; i++){
            for(int j = i + 1 ; j < numsSize; j++){
                if(nums[i] > nums[j]){
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
            }
        }
    
    for(int i = 0 ; i < numsSize ; i++){
        arr[i] = nums[i];
}   

    swap(arr,numsSize);

        *returnSize = numsSize;
        return arr; 
}


int main(){

 int numsSize = SIZE;
 int nums[SIZE] = {7,6,1,7,2,6}; // output must be : 2,1,6,6,7,7
 int arr[SIZE];
        for(int i = 0 ; i < numsSize ; i++){
            for(int j = i + 1 ; j < numsSize; j++){
                if(nums[i] > nums[j]){
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
            }
        }

    

for(int i = 0 ; i < numsSize ; i++){
    arr[i] = nums[i];
}

swap(arr,numsSize);

for(int i = 0 ; i < numsSize ; i++){
    printf("num %d : %d\n\n",i,nums[i]);


}


for(int i = 0 ; i < numsSize ; i++){
    if(i == numsSize-1){
        printf("%d",arr[i]);
    }else{
    printf("%d,",arr[i]);
}

}
}