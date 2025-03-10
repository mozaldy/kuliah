#include <stdio.h>

void main()
{
    float nilai_kali_jam = 0, total_jumlah_jam = 0;
    float ips = 0;  
    for (int i = 0; i < 5; i++)
    {
        char nilai;
        int jumlah_jam, nilai_bilangan;
        printf("Nilai mata kuliah 1: ");
        scanf(" %c", &nilai); //ILLEGAL
        printf("Jam 2: ");
        scanf("%d", &jumlah_jam);
        
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

        nilai_kali_jam += (nilai_bilangan * jumlah_jam);
        total_jumlah_jam += jumlah_jam;
    }
    ips = nilai_kali_jam / total_jumlah_jam;
    printf("Index Prestasi Semester: %.2f\n", ips);
}