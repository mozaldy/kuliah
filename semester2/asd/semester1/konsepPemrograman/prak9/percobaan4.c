#include <stdio.h>

void main()
{
    int n, hasil;
    printf("Angka dari 1 ke n, bilangan genap negatif, bilangan ganjil positif\nn: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        printf("%d ", (i % 2 == 0) ? -i : i);
    printf("\n");
}