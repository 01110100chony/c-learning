#include <stdio.h>
#include <stdlib.h>



int fib(int n){
    if(n == 1) return 1;
    if(n <= 0) return 0;
    return fib(n-1) + fib(n-2);
}


int main(){
    int n = 4;
    printf("fib : %d\n",fib(n));
}