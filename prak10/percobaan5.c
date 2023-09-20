#include <stdio.h>

void main()
{
    int count, count_spasi;
    char c;
    while (c != '\n')
    {
        c = getchar();
        if (c != '\n' && c != ' ')
            count++;
        else if (c == ' ')
            count_spasi++;
    }
    printf("Jumlah karakter = %d\n", count);
    printf("Jumlah spasi = %d\n", count_spasi);
}