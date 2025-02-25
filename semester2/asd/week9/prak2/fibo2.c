#include <stdio.h>
#include <stdlib.h>

int fibo_recursive(int, int);

int n;
int main(){
    printf("Input angka n: ");
    scanf("%d", &n);
    n -= 2;
    printf("Angka fibonacci dengan n = %d: \n", n);
    fibo_recursive(0, 1);
}

int fibo_recursive(int prev, int current){
    printf("%d, ", prev);
    if(!n){
        printf("%d.\n", current);
        exit(0);
    }

    n--;
    fibo_recursive(current, prev + current);
}