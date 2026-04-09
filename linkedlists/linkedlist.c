#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{
int n;
int index;
struct Node* prox;
}Node;


Node* criarNode(int valor,int index){
    Node* newNode = malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Erro ao criar node;\n");
        return NULL;
    }
    newNode->index = index;
    newNode->n = valor;

    newNode->prox = NULL;

    return newNode;

}

void inserirNode(Node* head,int valor,int index){
if(head==NULL){
    printf("Head null.\n");
}
Node *ptr,*temp;
ptr = head;
temp = malloc(sizeof(Node));

temp->n = valor;
temp->index = index;
temp->prox =  NULL;

while(ptr->prox != NULL){
    ptr = ptr->prox;  
}
ptr->prox = temp;
}



int main(){

srand(time(NULL));

Node* head = criarNode(1,0);

printf(" index : %d , n : %d \n\n ",head->index,head->n);

for(int i = 0 ; i < 10 ; i++){
int z , x;
z = rand()% 10000;
x = rand()% 10000;
inserirNode(head,z,x);
}

Node* atual;

atual = head;

while(atual != NULL){
    printf("index : %d , n : %d \n ", atual->index,atual->n);
    atual = atual->prox;
}




}