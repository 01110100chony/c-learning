#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TABLE_SIZE 100

typedef struct Node{
int valor;
int key;
struct Node* link;
}Node;

typedef struct HashMap{
    Node** buckets;
    int size;
}HashMap;


HashMap* initializeMap(){
    HashMap* map = malloc(sizeof(HashMap));
    map->size = TABLE_SIZE;
    map->buckets = malloc(TABLE_SIZE * sizeof(Node*));
    for(int i = 0 ; i < TABLE_SIZE ; i++){
        map->buckets[i] = NULL;
    }
return map;
}

unsigned int hash(int key){
unsigned int h = (unsigned int)key * 31; 
    return h % TABLE_SIZE;
}

void insert(HashMap* map,int key,int value){
   unsigned int slot = hash(key) % TABLE_SIZE;
    Node* temp = map->buckets[slot];
    
    while(temp != NULL){
        if(temp->key == key ){
            temp->valor = value;
            return; 
        }
        temp = temp->link;
    }
    
    Node* NovoNode = malloc(sizeof(Node));
    NovoNode->key = key;
    NovoNode->valor = value;
    NovoNode->link = map->buckets[slot];
    map->buckets[slot] = NovoNode;
}

void printhash(HashMap* map){
    for (int i = 0; i < map->size; i++) {
        printf("[%d]: ", i);
        Node* temp = map->buckets[i];
        if (temp == NULL) {
            printf("---\n");
        } else {
            while (temp != NULL) {
                printf("(K:%d, V:%d) -> ", temp->key, temp->valor);
                temp = temp->link;
            }
            printf("NULL\n");
        }
     }
  }

void destroyMap(HashMap* map){
    for(int i = 0 ; i < TABLE_SIZE ; i++){
        Node* temp = map->buckets[i];
        while(temp != NULL){
            Node* obliterator = temp;
            temp = temp->link;
            free(obliterator);
        }
    }
        free(map->buckets);
        free(map);
}
 
//key = valores, valor = index(key)
// Retorna 1 se achou, 0 se não. O valor vai para o ponteiro result
int search_safe(HashMap* map, int key, int* result) {
    unsigned int slot = hash(key) % TABLE_SIZE;
    Node* temp = map->buckets[slot];
    while (temp != NULL) {
        if (temp->key == key) {
            *result = temp->valor;
            return 1; 
        }
        temp = temp->link;
    }
    return 0;
}

    //precisamos de 2 inteiros que, tal que i + j = k, sendo k o target :
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    HashMap* map = initializeMap();
    int* indexes = NULL;

    for (int i = 0; i < numsSize; i++) {
        int complemento = target - nums[i];
        int valorEncontrado;


        if (search_safe(map, complemento, &valorEncontrado)) {
            indexes = malloc(2 * sizeof(int));
            indexes[0] = valorEncontrado; 
            indexes[1] = i;             
            *returnSize = 2;
            
            destroyMap(map);
            return indexes;
        }

       
        insert(map, nums[i], i);
    }

    destroyMap(map);
    *returnSize = 0;
    return NULL;
}