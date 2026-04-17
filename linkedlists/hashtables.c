#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h>
#define MAX_NAME 50
#define TABLE_SIZE 100

typedef struct Pessoa{
char nome[MAX_NAME];
int idade;
}Pessoa; //strtuct pra pessoa

Pessoa * hash_table[TABLE_SIZE]; //cria uma hash_table de table_size tamanho

unsigned int hashFunc(char *nome){ //recebe o nome como parametro pra hashear.
int tamanho = strnlen(nome,MAX_NAME); //determina o tamanho baseado em retorno de strnlen.
unsigned int hashValor = 0; //inicializa um valor hash
for(int i = 0 ; i < tamanho ; i++){
    hashValor += nome[i]; 
    hashValor = (hashValor * nome[i]) % TABLE_SIZE; //funcao principal de hashear, eh a formula pra "mascarar" a info
}
return hashValor; //retorna o valor hasheado
}

void init_hash(){
    for( int i = 0 ; i < TABLE_SIZE ; i++){
    hash_table[i] = NULL; //inicializa cada elemento da hash_table com NULL
  }
}

void print_hashtable(){
for(int i = 0  ; i < TABLE_SIZE ; i++){
    if(hash_table[i] == NULL){ 
        printf("\t%i\t---\n",i);//se nao tiver hash, printa isso
    } else {
        printf("\t%i\t%s\n",i,hash_table[i]->nome); //se houver elemento, printa o elemento da hash
    }
  }
}

bool insert_in_hash(Pessoa* p){ //usa parametro de uma pessoa em especifico pra insertar
if(p == NULL){ //se for NULL, retorna q deu ruim
    return false;
}
int index = hashFunc(p->nome);//cria um index par hash table baseado no nome da pessoa

if(hash_table[index] != NULL){ //se essa hash table ja for ocupada, retorna falso
    return false;
}
hash_table[index] = p; //faz a hashtable desse index apontar pra pessoa
return true;//retorna q foi sucedido
}

Pessoa* find_person(char* nome){ //parametro nome, ja que a ideia eh buscar por nome
int index = hashFunc(nome); //hasheia e atribui pra index
if(hash_table[index] != NULL && strcmp(hash_table[index]->nome, nome) == 0){ //se essa hash table tiver elemento e os nomes sao iguais,ok
    return hash_table[index]; //retorna a pessoa procurada apontada pelo hash_table 
}else{
    return NULL; 
}
}


int main(){

init_hash(); //inicia hash

print_hashtable(); //printa hash

printf("\n\n");

Pessoa p = {.nome ="joao", .idade =202556};
Pessoa p1 = {.nome ="jose", .idade =210};
Pessoa p2 = {.nome ="joabe", .idade =230};
Pessoa p3 = {.nome ="jagunco", .idade =20};
Pessoa p4 = {.nome ="jiboia", .idade =20022};
Pessoa p5 = {.nome ="jaburu", .idade =2001};

insert_in_hash(&p); 

insert_in_hash(&p1);

insert_in_hash(&p2);

insert_in_hash(&p3);

insert_in_hash(&p4);

insert_in_hash(&p5);//inserta na hashtable


print_hashtable();

printf("\n\n\n");


printf("\t%u\t%s\t%d\n",hashFunc("joao"),find_person("joao")->nome,find_person("joao")->idade);

/*
printf("Joao => %u\n",hashFunc("Joao"));

printf("Jose => %u\n",hashFunc("Jose"));

printf("Jagunco => %u\n",hashFunc("Jagunco"));

printf("Jiboia => %u\n",hashFunc("Jiboia"));

printf("Jeronimo => %u\n",hashFunc("Jeronimo"));

printf("Joabe => %u\n",hashFunc("Joabe"));

*/







return 0;
}








