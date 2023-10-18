#include <stdio.h>

void deret(int);

void main()
{
    int input;
    printf("Masukkan batas n: ");
    scanf("%d", &input);
    deret(input);
}

void deret(int n)
{
    int angka = 1, suku = 1;
    printf("Deret: ");
    while (suku <= n)
    {
        printf("%d ", angka);
        if (suku % 3 == 0)
            angka += 3;
        else if (suku % 3 == 1)
            angka++;
        else
            angka += 2;
        suku++;
    }
}