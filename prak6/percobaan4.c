#include <stdio.h>

void main()
{
    int angka;
    printf("Nilai angka: ");
    scanf("%d", &angka);
    if (angka <= 40)
    {
        printf("Nilai char huruf adalah E\n");
    }
    else if (angka > 40 && angka <= 55)
    {
        printf("Nilai char huruf adalah D\n");
    }
    else if (angka > 55 && angka <= 60)
    {
        printf("Nilai char huruf adalah C\n");
    }
    else if (angka > 60 && angka <= 80)
    {
        printf("Nilai char huruf adalah B\n");
    }
    else if (angka > 80 && angka <= 100)
    {
        printf("Nilai char huruf adalah A\n");
    }
    else
    {
        printf("Angka tidak valid!\n");
        return;
    }
}