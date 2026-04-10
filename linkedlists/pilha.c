#include <stdio.h>
#include <stdlib.h>


#include <stdio.h>

/*Você está construindo uma pilha estática que guarda caracteres como na struct abaixo.  

Crie uma função que recebe como entrada um ponteiro para a pilha e um caractere e adicione o caractere à pilha. */

// elemento usado (não modificar)
struct pilha_t{
    char dados[50];     // array de dados
    int qtd;            // número de elemenotos na pilha
};
typedef struct pilha_t pilha;

void adiciona_caractere(pilha *p, char c){
    p->dados[p->qtd] = c;
    p->qtd++;
}


int main(){
pilha p;
p.qtd=0;
adiciona_caractere(&p, 'X');
printf("%c", p.dados[0]);
}