#include <stdio.h>

void main()
{
    int n, bilangan_ganjil = 1;
    printf("Bilangan ganjil ke n\nn: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", bilangan_ganjil);
        bilangan_ganjil = bilangan_ganjil + 2;
    }
    printf("\n");
}