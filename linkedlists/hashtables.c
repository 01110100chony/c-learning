#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h>
#define MAX_NAME 50
#define TABLE_SIZE 10

typedef struct Pessoa{

char nome[MAX_NAME];
int idade;


}Pessoa;

Pessoa * hash_table[TABLE_SIZE];

unsigned int hashFunc(char *nome){
int tamanho = strnlen(nome,MAX_NAME);
unsigned int hashValor = 0;
for(int i = 0 ; i < tamanho ; i++){
    hashValor += nome[i];
    hashValor = (hashValor * nome[i]) % TABLE_SIZE;
}


return hashValor;
}

void init_hash(){
    for( int i = 0 ; i < TABLE_SIZE ; i++){
    hash_table[i] = NULL;
  }
}

void print_hashtable(){
for(int i = 0  ; i < TABLE_SIZE ; i++){
    if(hash_table[i] == NULL){
        printf("\t%i\t---\n",i);
    } else {
        printf("\t%i\t%s\n",i,hash_table[i]->nome);
    }
  }
}

bool insert_in_hash(Pessoa* p){
if(p == NULL){
    return false;
}
int index = hashFunc(p->nome);

if(hash_table[index] != NULL){
    return false;
}
hash_table[index] = p;
return true;
}



int main(){

init_hash();

print_hashtable();

printf("\n\n");

Pessoa p = {.nome ="joao", .idade =202};
Pessoa p1 = {.nome ="jose", .idade =2150};
Pessoa p2 = {.nome ="joabe", .idade =230};
Pessoa p3 = {.nome ="jagunco", .idade =20};
Pessoa p4 = {.nome ="jiboia", .idade =20022};
Pessoa p5 = {.nome ="jaburu", .idade =2001};

insert_in_hash(&p);

insert_in_hash(&p1);

insert_in_hash(&p2);

insert_in_hash(&p3);

insert_in_hash(&p4);

insert_in_hash(&p5);


print_hashtable();
/*
printf("Joao => %u\n",hashFunc("Joao"));

printf("Jose => %u\n",hashFunc("Jose"));

printf("Jagunco => %u\n",hashFunc("Jagunco"));

printf("Jiboia => %u\n",hashFunc("Jiboia"));

printf("Jeronimo => %u\n",hashFunc("Jeronimo"));

printf("Joabe => %u\n",hashFunc("Joabe"));

*/








}








