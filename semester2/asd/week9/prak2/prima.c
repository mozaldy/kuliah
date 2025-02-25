#include <stdio.h>
#include <math.h>

int is_prime(int, int);

int main() {
    int angka;

    printf("Masukkan angka: ");
    scanf("%d", &angka);

    if (is_prime(angka, 2))
        printf("%d adalah bilangan prima\n", angka);
    else
        printf("%d bukan bilangan prima\n", angka);

}

int is_prime(int n, int i) {
    if (n % i == 0 || n <= 1)
        return 0;
    else if (i > sqrt(n))
        return 1;
    else
        return is_prime(n, i + 1);
}