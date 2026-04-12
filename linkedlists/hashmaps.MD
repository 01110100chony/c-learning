# Intuition

I tried the brute force solution (2 loops) first, but it ended up being so slow at O(n^2) and obviously not the optimal solution. I ended up learning about hashmaps/hashtables so I could obtain an O(n) on this solution.



# Approach

My approach was :

 - Creating a node that contains a value, and a key, and a link to the next node, then creating a HashMap that contains a Node** buckets which contains other *nodes.It is a obligation to use ** when dealing with a Hash Type Structure, because we create a array of pointer to single-linked-lists and the only way to manipulate the values within Node is deferencing 2 times.

 

 - Then I initialized the hashmap with $$initializemap()$$ , which basically allocate dynamically memory for the structure map , and then allocate  memory dinamically for each node in a for loop; it returns a map, which is the base of my code.

 - Next, I created the hash function. $$hash()$$ basically takes the key, that is , the nums[i] of the $$twoSum()$$ , multiplies it by 31 and mod it (%) in respect to TABLE_SIZE. I used 101 , but it depends on the sample scenario. 1 as TABLE_SIZE would make it just a simple linked list, and we don't want that. 101 is a sweet spot.

 - Then, I created the $$insert()$$ function, which takes a map, a key(numS[i]) and the index(value) . A slot is created, based on the hashed version of the numS[i] or key. Then with a Node* pointer or temp,etc, we assign this temp the buckets[] of the hashed key. If it is already filled and the key of the filled temp is the same as the key parameter of the function, we fill the index again with the value. When the last position of the node is null, we can proceed to dynamically alloc the memory to the new node, assign the values of the function parameter to the new node, and then update the head, making this new node the head and the last head the link of this node. Note that this is the key point that makes this function O(n) , adding to the beginning will always be faster than going to ALL the position and then adding it to the tail. Not optimal at all.

 - $$destroyMap()$$ receives a map and kills it. Simple as that, but carefully freeing from the inside to the outside ; first, using a ptr to transverse every buckets[i] of the map, and inside this bucket , creating a temp for every node linked to this bucket and freeing this temp. It is the safest way to clear the memory of the nodes. After that, freeing the malloced buckets and the malloced map is mandatory practice.

 - $$search_safe()$$ takes a map, a key , and a pointer, the key will be hashed and searched through the respective bucket, will be transversed through the nodes until we find the value desired. if it finds the value, it stores the pointer to the index desired and return 1, if it doesn't find, it will transverse through the bucket until it finds. If it gets to NULL and doesn't find anyway, return 0.

 - As the main function $$twoSum()$$ , we receive the array of nums , the size of the array, the target we want to use such as  i + j = target, and the returnSize of the array. Which, obviously, when it is a valid case, will return 2, and when there isn't values that satisfy i + j = k will return 0.

 - After understanding what these parameter means to our new vision striving a O(n) , we can follow with $$initializeMap()$$ , create a array of indexes which is NULL, and , on the main for loop, we fix the numS[i] at i , and calculate which part is missing from the numS[i] such that target - nums[i] = complement. Then we use a foundValue( or valorEncontrado in my lang) to work as our stored index. - -

 - Following, if $$search_safe()$$ returns 1 ( the value is found ), we malloc the array of indexes, assign the first element of the array as the found value,and the second as the i , which is the index of our fixed nums[i]. then destroymap,etc,etc and return the indexes and the returnSize. In the case it doesn't find first, we store this hashed value of nums[i] of index [i] in the map. It will loop in O(n) until we find the complement and return the indexes. If there isn't a j such as  i + j = target, we destroy the map and the returnsize. That is the case we can't satisfy at all costs.



##TL;DR:##

We use a hash map to map the nums[i] to a certain position in our map, deal with collisions, deal with memory management efficiently , search for a value that satisfy {nums[i] + value = target} in our HashMap and through ALL nodes of the buckets, then return the indexes of the values that satisfied it . In the case it doesn't satisfy , the returnSize is 0 and the indexes is twoSum is NULL;



sorry for my bad english, I'm not that good at writing long texts xd







# Complexity

- Time complexity:

$$O(n)$$



- Space complexity:





# Code

```c []

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <time.h>

#define TABLE_SIZE 101



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

 

//key = valores, valor = index(key).

// rretorna 1 se achou, 0 se não. O valor vai para o ponteiro 'result'

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

```