#include <stdio.h>

void main()
{
    int n, hasil;
    printf("Angka ganjil dari 1 = ke n\nn: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        hasil = (i % 2 == 0) ? (i * -1) : i;
        printf("%d ", hasil);
    }
    printf("\n");
}