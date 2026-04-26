#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isPalindromo(const char* s){

    int size = strlen(s);

    char* buffer = calloc(size + 1, sizeof(char)); 

    if(!buffer){
        perror("Zuou o malloc doguxo");
    }

    for(int i = 0,j = size - 1 ; i < size ; i++ , j--){
        buffer[i] = s[j];
    }

    printf("Sentenca original = %s\n",s);
    printf("Sentenca invertida = %s\n",buffer);

    return strncmp(buffer, s, size) == 0;
      
}

bool isPalindromo2(const char* s){

    int size = strlen(s);

    int left = 0;
    int right = size - 1;

    while(left < right){
        if(s[left] != s[right]){
            return false;
        } else {
            left++;
            right--;
        }
    }
    return true;
}

int main(){


    const char* s = "arara";

    if(isPalindromo(s)){
        printf("Eh palindromo\n");
    } else {
        printf("Nao eh palindromo\n");
    }

    printf("\n\n\n");

    if(isPalindromo2(s)){
        printf("Eh palindromo\n");
    } else {
        printf("Nao eh palindromo\n");
    }
    













}