#include <stdio.h>

void main()
{
    int menu;
    float angka_pertama, angka_kedua, hasil;
    printf("Masukkan bilangan pertama: ");
    scanf("%f", &angka_pertama);
    printf("Masukkan bilangan kedua: ");
    scanf("%f", &angka_kedua);
    printf("Menu Matematika\n");
    printf("1. Penjumlahan\n");
    printf("2. Pengurangan\n");
    printf("3. Pembagian\n");
    printf("4. Perkalian\n");
    printf("Masukkan pilihan anda: ");
    scanf("%d", &menu);

    switch (menu)
    {
    case 1:
        hasil = angka_pertama + angka_kedua;
        break;
    case 2:
        hasil = angka_pertama - angka_kedua;
        break;
    case 3:
        hasil = angka_pertama / angka_kedua;
        break;
    case 4:
        hasil = angka_pertama * angka_kedua;
        break;
    
    default:
        printf("Operator tidak valid!\n");
        break;
    }
    printf("Hasil dari operasi tersebut = %.1f\n", hasil);
}
