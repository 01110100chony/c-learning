#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int firstUniqChar(char* s) {
    
    for(int i = 0 ; s[i] != '\0' ; i++){
        int repeat = 0;
        for(int j = 0 ; s[j] != '\0' ; j++){
            if(i==j) continue;

            if(s[i] == s[j]){ repeat = 1;
            break;
            }
        }
        if(repeat == 0) return i;   
    }
    return -1;
}

int main(){


char *s = malloc(100 * sizeof(char));

strcpy(s,"loveleetcode");

 for(int i = 0 ; s[i] != '\0' ; i++){
        printf("%c",s[i]);
    }
    printf("\n\n\n\n");

    printf("%d\n",firstUniqChar(s));




}