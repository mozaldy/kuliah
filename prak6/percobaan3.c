#include <stdio.h>

void main()
{
    int angka_pertama, angka_kedua, menu, hasil;
    printf("Masukkan bilangan pertama: ");
    scanf("%d", &angka_pertama);
    printf("Masukkan bilangan kedua: ");
    scanf("%d", &angka_kedua);
    printf("Menu Matematika\n");
    printf("1. Penjumlahan\n");
    printf("2. Pengurangan\n");
    printf("3. Pembagian\n");
    printf("4. Perkalian\n");
    printf("Masukkan pilihan anda: ");
    scanf("%d", &menu);

    if (menu == 1)
    {
        hasil = angka_pertama + angka_kedua;
    }
    else if (menu == 2)
    {
        hasil = angka_pertama - angka_kedua;
    }
    else if (menu == 3)
    {
        hasil = angka_pertama / angka_kedua;
    }
    else if (menu == 4)
    {
        hasil = angka_pertama * angka_kedua;
    }
    else
    {
        printf("Menu tidak valid!\n");
        return;
    }
    printf("Hasil dari operasi tersebut = %d\n", hasil);
}
