#include <stdio.h>

// elemento usado (não modificar)
struct Pessoa_tipo{
    char nome[50];
    int idade;
    struct Pessoa_tipo *prox;
};
typedef struct Pessoa_tipo pessoa;

// função a ser desenvolvida:
int maiores(pessoa *p){
    int n = 0;
    pessoa* ptr = p;
    if(ptr == NULL) return 0;
    while(ptr->prox != NULL){
        if(ptr->idade > 21){
            n++;
        }
        ptr = ptr->prox;
    }
    return n;
}



int main(){

pessoa p[3] = {{"ana", 20, NULL}, {"ze", 22, NULL}, {"bia", 18, NULL}};
p[0].prox = &p[1];p[1].prox = &p[2];
printf("%d", maiores(&p[0]));
}