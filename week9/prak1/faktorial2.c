#include <stdio.h>

long long int factorial(int n);

long long int permutation(int n, int r);
long long int combination(int n, int r);

int main() {
    int n, r;
    
    printf("Masukkan nilai n: ");
    scanf("%d", &n);
    printf("Masukkan nilai r: ");
    scanf("%d", &r);
    
    if (n < r) {
        printf("Nilai n harus lebih besar dari atau sama dengan r.\n");
        return 1;
    }
    
    long long int perm = permutation(n, r);
    long long int comb = combination(n, r);
    
    printf("Permutasi dari N = %d & R = %d adalah %lld\n", n, r, perm);
    printf("Kombinasi dari N = %d & R = %d adalah %lld\n", n, r, comb);
    
    return 0;
}

long long int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

long long int permutation(int n, int r) {
    return factorial(n) / factorial(n - r);
}

long long int combination(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}
