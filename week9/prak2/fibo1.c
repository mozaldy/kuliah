#include <stdio.h>

int fibo(int);

int main(){
    int n;
    printf("Input angka n: ");
    scanf("%d", &n);
    fibo(n);

}

int fibo(int n){
    int fibo_array[n];
    fibo_array[0] = 0;
    fibo_array[1] = 1;
    for (int i = 2; i < n; i++)
        fibo_array[i] = fibo_array[i - 1] + fibo_array[i - 2];
    printf("Angka fibonacci dengan n = %d: \n", n);
    for (int i = 0; i < n; i++){
        if (i == n - 1)
            printf("%d.\n", fibo_array[i]);
        else        
            printf("%d, ", fibo_array[i]);
    }
}