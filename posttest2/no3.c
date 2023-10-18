#include <stdio.h>

int konversi_biner(int);
int dua_pangkat(int);
void main()
{
    int angka;
    scanf("%d", &angka);
    printf("%d\n", konversi_biner(angka));
}

int konversi_biner(int biner)
{
    int hasil = 0, pangkat = 0;
    while (biner > 0)
    {
        if (biner % 10 == 1)
        {
            hasil += dua_pangkat(pangkat);
        }
        biner /= 10;
        pangkat++;
    }
    return hasil;
}

int dua_pangkat(int pangkat)
{
    if (pangkat == 0)
    {
        return 1;
    }
    int angka = 2, n = 1;
    for (int i = 0; i < pangkat; i++)
    {
        n *= angka;
    }
    return n;
}