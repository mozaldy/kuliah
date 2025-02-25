#include <stdio.h>

int factorial(int);
int permutasi(int, int);
int kombinasi(int, int);

void main()
{
    int n, r;
    printf("Input n: ");
    scanf("%d", &n);
    printf("Input r: ");
    scanf(" %d", &r);
    printf("Permutasi: %d \n", permutasi(n, r));
    printf("Kombinasi: %d \n", kombinasi(n, r));
}

int factorial(int n)
{
    int hasil = 1;
    for (int i = 1; i <= n; i++)
        hasil *= i;
    return hasil;
}

int permutasi(int n, int r)
{
    return factorial(n) / factorial(n - r);
}

int kombinasi(int n, int r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));
}