#include <stdio.h>

void main()
{
    int count = 0, count_spasi = 0, count_char_kecil = 0, count_char_besar = 0, count_angka = 0;
    char c;
    while (c != '\n')
    {
        c = getchar();
        if (c != '\n' && c != ' ')
        {
            if (c >= 97 && c <= 122)
                count_char_kecil++;
            else if (c >= 62 && c <= 90)
                count_char_besar++;
            else if (c >= 48 && c <= 57)
                count_angka++;
            count++;
        }
        else if (c == ' ')
            count_spasi++;
    }
    printf("Jumlah karakter = %d\n", count);
    printf("Jumlah spasi = %d\n", count_spasi);
    printf("Jumlah huruf besar = %d\n", count_char_besar);
    printf("Jumlah huruf kecil = %d\n", count_char_kecil);
    printf("Jumlah angka = %d\n", count_angka);
}