#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TABLE_SIZE 20000

typedef struct Node{
    int value;
    int key;
    struct Node* next;
}Node;

typedef struct Hashmap{
Node* buckets[TABLE_SIZE];
}Hashmap;

unsigned int hash(int key){
   return (unsigned int)(abs(key)) % TABLE_SIZE;
}


int* twoSum(int* nums, int numsSize, int target, int* returnSize);
  


int main(){

Node* node = malloc(sizeof(Node));
if(node==NULL) return 1;

node->key = 3;
node->value = 10;
node->next = NULL;

unsigned int h = hash(node->key);

printf("%u\n\n",h);

printf("%u\n\n",hash(3));

printf("%u\n\n",hash(100));

free(node);






}