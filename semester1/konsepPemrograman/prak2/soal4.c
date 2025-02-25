#include <stdio.h>

void main()
{
    int bilangan_satu, bilangan_dua;
    printf("Bilangan 1:\n");
    scanf("%d", &bilangan_satu);
    printf("Bilangan 2:\n");
    scanf("%d", &bilangan_dua);
    printf("Operasi Aritmatika dari %d dan %d:\n", bilangan_satu, bilangan_dua);
    printf("1. Penjumlahan: %d\n", bilangan_satu + bilangan_dua);
    printf("2. Rata-rata: %d\n", (bilangan_satu + bilangan_dua) / 2);
    printf("3. Kuadrat:\n   %d kuadrat = %d\n   %d kuadrat = %d\n", bilangan_satu, bilangan_satu * bilangan_satu, 
    bilangan_dua, bilangan_dua * bilangan_dua);
}