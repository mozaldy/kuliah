#include <stdio.h>

void main()
{
    int ips = 0, nilai_kali_jam = 0, total_jumlah_jam = 0;
    for (int i = 0; i < 5; i++)
    {
        char nilai;
        int jumlah_jam, nilai_bilangan;
        printf("Nilai mata kuliah 1: ");
        scanf("%c", &nilai);
        fflush(stdin);

        switch (nilai)
        {
        case 'A':
            nilai_bilangan = 4;
            break;
        case 'B':
            nilai_bilangan = 3;
            break;
        case 'C':
            nilai_bilangan = 2;
            break;
        case 'D':
            nilai_bilangan = 1;
            break;
        case 'E':
            nilai_bilangan = 0;
            break;

        default:
            break;
        }

        printf("Jam: ");
        scanf("%d", &jumlah_jam);

        nilai_kali_jam += (nilai_bilangan * jumlah_jam);
        total_jumlah_jam += jumlah_jam;
    }
    ips = nilai_kali_jam / total_jumlah_jam;
    printf("Index Prestasi Semester: %d\n", ips);
}