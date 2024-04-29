#include <stdio.h>
#include <stdlib.h>

int fibo_recursive(int, int);
int fibo(int);

int n;
int main(){
    int pilihan;
    printf("Input angka n: ");
    scanf("%d", &n);
    printf("1. Fibonacci dengan iterasi\n2. Fibonacci dengan rekursi\nPilihan anda: ");
    scanf("%d", &pilihan);
    printf("Angka fibonacci dengan n = %d: \n", n);
    switch (pilihan)
    {
    case 1:
        fibo(n);
        break;
    case 2:
        n -= 2;
        fibo_recursive(0, 1);
        break;
    default:
        break;
    }
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

int fibo(int n){
    int fibo_array[n];
    fibo_array[0] = 0;
    fibo_array[1] = 1;
    for (int i = 2; i < n; i++)
        fibo_array[i] = fibo_array[i - 1] + fibo_array[i - 2];
    for (int i = 0; i < n; i++){
        if (i == n - 1)
            printf("%d.\n", fibo_array[i]);
        else        
            printf("%d, ", fibo_array[i]);
    }
}